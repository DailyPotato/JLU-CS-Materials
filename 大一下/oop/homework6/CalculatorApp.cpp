#include "CalculatorApp.h"

#include "ArithmeticEngine.h"
#include "ConsoleOutput.h"
#include "FileOutput.h"
#include "Shape.h"
#include "StatisticsManager.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const char* CalculatorApp::VERSION = "v1.0";

namespace {
bool isArithmeticCommand(const std::string& cmd)
{
    return cmd == "+" || cmd == "-" || cmd == "*"
        || cmd == "/" || cmd == "%";
}

bool isShapeCommand(const std::string& cmd)
{
    return cmd == "rectangle" || cmd == "triangle" || cmd == "circle";
}

bool parseDouble(const std::string& token, double& value)
{
    std::stringstream ss(token);
    char extra = '\0';
    return (ss >> value) && !(ss >> extra);
}

bool parseInt(const std::string& token, int& value)
{
    double temp = 0.0;
    if (!parseDouble(token, temp) || temp != static_cast<int>(temp)) {
        return false;
    }
    value = static_cast<int>(temp);
    return true;
}

std::string formatDouble(double value)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value;
    return oss.str();
}

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

CalculatorApp::CalculatorApp()
    : CalculatorApp(VERSION)
{
}

CalculatorApp::CalculatorApp(const char* version)
    : m_engine(new ArithmeticEngine()),
      m_stats(new StatisticsManager()),
      m_output(new ConsoleOutput()),
      m_lastShape(nullptr)
{
    std::cout << "CalculatorApp " << version << " created" << std::endl;
}

CalculatorApp::~CalculatorApp()
{
    std::cout << "CalculatorApp destroyed" << std::endl;
    delete m_output;
    m_output = nullptr;
    delete m_lastShape;
    m_lastShape = nullptr;
    delete m_stats;
    m_stats = nullptr;
    delete m_engine;
    m_engine = nullptr;
}

void CalculatorApp::setFileOutput()
{
    delete m_output;
    m_output = new FileOutput();
}

void CalculatorApp::runInteractive()
{
    std::cout << "Calculator App " << VERSION << " started." << std::endl;

    std::string line;
    while (true) {
        std::cout << "Enter command (or 'exit'): ";
        if (!std::getline(std::cin, line)) {
            std::cout << std::endl;
            m_output->saveStats(*m_stats);
            break;
        }

        if (processLine(line)) {
            break;
        }
    }
}

int CalculatorApp::runCommandLine(int argc, char* argv[])
{
    std::vector<std::string> args;
    for (int i = 1; i < argc; ++i) {
        std::string current = argv[i];
        if (current == "--output") {
            if (i + 1 >= argc || std::string(argv[i + 1]) != "file") {
                std::cout << "Error: invalid output option" << std::endl;
                return 1;
            }
            setFileOutput();
            ++i;
        } else {
            args.push_back(current);
        }
    }

    if (args.empty()) {
        std::cout << "Error: invalid argument count" << std::endl;
        return 1;
    }

    bool validFormat = false;
    bool validNumbers = false;
    if (args.size() == 3 && isArithmeticCommand(args[1])) {
        int a = 0;
        int b = 0;
        validFormat = true;
        validNumbers = parseInt(args[0], a) && parseInt(args[2], b);
    } else if (args.size() == 2 && args[0] == "circle") {
        double radius = 0.0;
        validFormat = true;
        validNumbers = parseDouble(args[1], radius);
    } else if (args.size() == 3
               && (args[0] == "rectangle" || args[0] == "triangle")) {
        double a = 0.0;
        double b = 0.0;
        validFormat = true;
        validNumbers = parseDouble(args[1], a) && parseDouble(args[2], b);
    } else if (args.size() == 1 && args[0] == "copy") {
        validFormat = true;
        validNumbers = true;
    }

    if (!validFormat) {
        std::cout << "Error: invalid argument count" << std::endl;
        return 1;
    }
    if (!validNumbers) {
        std::cout << "Error: non-numeric input" << std::endl;
        return 1;
    }

    std::ostringstream line;
    for (std::size_t i = 0; i < args.size(); ++i) {
        if (i != 0) {
            line << ' ';
        }
        line << args[i];
    }

    if (!processLine(line.str())) {
        m_output->saveStats(*m_stats);
    }
    return 0;
}

bool CalculatorApp::processLine(const std::string& line)
{
    std::stringstream ss(line);
    std::vector<std::string> tokens;
    std::string token;

    while (ss >> token) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        m_output->print("Error: empty input");
        return false;
    }

    if (tokens[0] == "exit") {
        if (tokens.size() != 1) {
            m_output->print("Error: invalid command format");
            return false;
        }
        m_output->saveStats(*m_stats);
        return true;
    }

    if (tokens[0] == "reset") {
        if (tokens.size() != 1) {
            m_output->print("Error: invalid command format");
            return false;
        }
        m_stats->resetStats();
        m_output->print("Statistics reset");
        return false;
    }

    if (tokens[0] == "copy") {
        if (tokens.size() != 1) {
            m_output->print("Error: invalid command format");
            return false;
        }
        processCopy();
        return false;
    }

    if (tokens.size() == 3 && isArithmeticCommand(tokens[1])) {
        int a = 0;
        int b = 0;
        if (!parseInt(tokens[0], a) || !parseInt(tokens[2], b)) {
            m_output->print("Error: non-numeric input");
            return false;
        }
        processArithmetic(tokens[1], a, b);
        return false;
    }

    if (isShapeCommand(tokens[0])) {
        double a = 0.0;
        double b = 0.0;
        if (tokens[0] == "circle") {
            if (tokens.size() != 2 || !parseDouble(tokens[1], a)) {
                m_output->print("Error: invalid command format");
                return false;
            }
            processCommand(tokens[0], a, b, 1);
            return false;
        }

        if (tokens.size() != 3
            || !parseDouble(tokens[1], a)
            || !parseDouble(tokens[2], b)) {
            m_output->print("Error: invalid command format");
            return false;
        }
        processCommand(tokens[0], a, b, 2);
        return false;
    }

    m_output->print("Error: invalid operator or shape name");
    return false;
}

void CalculatorApp::processCommand(const std::string& cmd,
                                   double a, double b, int argCount)
{
    if (isShapeCommand(cmd)) {
        processShape(cmd, a, b, argCount);
    } else {
        m_output->print("Error: invalid operator or shape name");
    }
}

void CalculatorApp::processArithmetic(const std::string& cmd, int a, int b)
{
    if (cmd == "+") {
        int result = m_engine->add(a, b);
        m_stats->incAdd();
        if (!resultWouldBeOutOfRange(cmd, a, b)) {
            m_output->print(std::to_string(a) + " + " + std::to_string(b)
                            + " = " + std::to_string(result));
        }
    } else if (cmd == "-") {
        int result = m_engine->subtract(a, b);
        m_stats->incSub();
        if (!resultWouldBeOutOfRange(cmd, a, b)) {
            m_output->print(std::to_string(a) + " - " + std::to_string(b)
                            + " = " + std::to_string(result));
        }
    } else if (cmd == "*") {
        int result = m_engine->multiply(a, b);
        m_stats->incMul();
        if (!resultWouldBeOutOfRange(cmd, a, b)) {
            m_output->print(std::to_string(a) + " * " + std::to_string(b)
                            + " = " + std::to_string(result));
        }
    } else if (cmd == "/") {
        int result = m_engine->divide(a, b);
        m_stats->incDiv();
        if (b != 0) {
            m_output->print(std::to_string(a) + " / " + std::to_string(b)
                            + " = " + std::to_string(result));
        }
    } else if (cmd == "%") {
        int result = m_engine->mod(a, b);
        m_stats->incMod();
        if (b != 0) {
            m_output->print(std::to_string(a) + " % " + std::to_string(b)
                            + " = " + std::to_string(result));
        }
    }
}

void CalculatorApp::processShape(const std::string& cmd,
                                 double a, double b, int argCount)
{
    Shape* currentShape = nullptr;

    if (cmd == "rectangle" && argCount == 2) {
        // 向上类型转换：new Rectangle 得到 Rectangle*，可赋值给 Shape*
        // 是因为 Rectangle 公有继承自 Shape，符合 is-a 赋值兼容规则。
        currentShape = new Rectangle(a, b);
    } else if (cmd == "triangle" && argCount == 2) {
        currentShape = new Triangle(a, b);
    } else if (cmd == "circle" && argCount == 1) {
        // Shape* s = new Circle(5) 是典型向上类型转换，后续虚函数动态绑定。
        currentShape = new Circle(a);
    } else {
        m_output->print("Error: invalid command format");
        return;
    }

    if (!currentShape->isValid()) {
        // 通过基类指针调用虚函数，运行时动态绑定到真实派生类实现。
        m_output->print("Error: side length or radius must be positive");
        delete currentShape;
        return;
    }

    double area = currentShape->area();
    if (cmd == "rectangle") {
        m_output->print("Rectangle area = " + formatDouble(area));
        m_stats->incRect();
    } else if (cmd == "triangle") {
        m_output->print("Triangle area = " + formatDouble(area));
        m_stats->incTri();
    } else {
        m_output->print("Circle area = " + formatDouble(area));
        m_stats->incCircle();
    }

    delete m_lastShape;
    m_lastShape = currentShape;
}

void CalculatorApp::processCopy()
{
    if (m_lastShape == nullptr) {
        m_output->print("No previous shape to copy");
        return;
    }

    // clone() 是虚函数：m_lastShape 只暴露 Shape*，实际复制哪个派生类
    // 由运行时对象类型决定，这就是虚拟拷贝的多态使用场景。
    Shape* copied = m_lastShape->clone();
    m_output->print("Copied shape, area = " + formatDouble(copied->area()));
    delete copied;
}
