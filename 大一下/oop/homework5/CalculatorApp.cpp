#include "CalculatorApp.h"

#include "ArithmeticEngine.h"
#include "InputParser.h"
#include "StatisticsManager.h"

#include <iomanip>
#include <iostream>

const char* CalculatorApp::VERSION = "v1.0";

namespace {
bool resultWouldBeOutOfRange(const std::string& cmd, int a, int b)
{
    long long result = 0;

    if (cmd == "+") {
        result = static_cast<long long>(a) + b;
    } else if (cmd == "-") {
        result = static_cast<long long>(a) - b;
    } else if (cmd == "*") {
        result = static_cast<long long>(a) * b;
    } else {
        return false;
    }

    return result < -ArithmeticEngine::MAX_VALUE
        || result > ArithmeticEngine::MAX_VALUE;
}
}

// 委托构造：公开构造函数委托给带版本号的私有构造函数。
CalculatorApp::CalculatorApp()
    : CalculatorApp(VERSION)
{
}

CalculatorApp::CalculatorApp(const char* version)
    : m_engine(new ArithmeticEngine()),
      m_stats(new StatisticsManager())
{
    // 生命周期管理：在构造函数中创建被组合对象。
    std::cout << "CalculatorApp " << version << " created" << std::endl;
}

CalculatorApp::~CalculatorApp()
{
    std::cout << "CalculatorApp destroyed" << std::endl;
    // 生命周期管理：在析构函数中按相反顺序释放组合对象。
    delete m_stats;
    delete m_engine;
}

void CalculatorApp::runInteractive()
{
    InputParser parser; // 局部对象：体现依赖关系，而不是成员对象。
    std::cout << "Calculator App " << VERSION << " started." << std::endl;

    std::string line;
    while (true) {
        std::cout << "Enter command (or 'exit'): ";
        if (!std::getline(std::cin, line)) {
            std::cout << std::endl;
            m_stats->printStats();
            break;
        }

        std::string cmd;
        int a = 0;
        int b = 0;

        if (!parser.parseInteractiveLine(line, cmd, a, b)) {
            continue;
        }

        if (cmd == "exit") {
            m_stats->printStats();
            break;
        }

        if (cmd == "reset") {
            m_stats->resetStats();
            std::cout << "Statistics reset" << std::endl;
            continue;
        }

        processCommand(cmd, a, b);
    }
}

int CalculatorApp::runCommandLine(int argc, char* argv[])
{
    InputParser parser; // 局部对象：体现依赖关系，而不是成员对象。
    std::string cmd;
    int a = 0;
    int b = 0;

    if (!parser.parseCommandLine(argc, argv, cmd, a, b)) {
        return 1;
    }

    processCommand(cmd, a, b);
    m_stats->printStats();
    return 0;
}

void CalculatorApp::processCommand(const std::string& cmd, int a, int b)
{
    if (cmd == "+") {
        int result = m_engine->add(a, b);
        m_stats->incAdd();
        if (!resultWouldBeOutOfRange(cmd, a, b)) {
            std::cout << a << " + " << b << " = " << result << std::endl;
        }
    } else if (cmd == "-") {
        int result = m_engine->subtract(a, b);
        m_stats->incSub();
        if (!resultWouldBeOutOfRange(cmd, a, b)) {
            std::cout << a << " - " << b << " = " << result << std::endl;
        }
    } else if (cmd == "*") {
        int result = m_engine->multiply(a, b);
        m_stats->incMul();
        if (!resultWouldBeOutOfRange(cmd, a, b)) {
            std::cout << a << " * " << b << " = " << result << std::endl;
        }
    } else if (cmd == "/") {
        int result = m_engine->divide(a, b);
        m_stats->incDiv();
        if (b != 0) {
            std::cout << a << " / " << b << " = " << result << std::endl;
        }
    } else if (cmd == "%") {
        int result = m_engine->mod(a, b);
        m_stats->incMod();
        if (b != 0) {
            std::cout << a << " % " << b << " = " << result << std::endl;
        }
    } else if (cmd == "rectangle") {
        double area = m_engine->rectangleArea(a, b);
        m_stats->incRect();
        if (a > 0 && b > 0) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Rectangle area (" << a << " x " << b
                      << ") = " << area << std::endl;
            std::cout << std::defaultfloat;
        }
    } else if (cmd == "triangle") {
        double area = m_engine->triangleArea(a, b);
        m_stats->incTri();
        if (a > 0 && b > 0) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Triangle area (" << a << " x " << b
                      << ") = " << area << std::endl;
            std::cout << std::defaultfloat;
        }
    } else {
        std::cout << "Error: invalid operator or shape name" << std::endl;
    }
}
