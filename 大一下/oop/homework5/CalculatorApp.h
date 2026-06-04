#ifndef CALCULATOR_APP_H
#define CALCULATOR_APP_H

#include <string>

// 前向声明用于降低编译依赖。本头文件只需要声明指针成员，
// 完整类定义放到 CalculatorApp.cpp 中包含。
class ArithmeticEngine;
class StatisticsManager;

// 总入口类：负责协调运算引擎、统计管理器和输入解析器完成整体功能。
// 它拥有运算引擎和统计管理器，并在成员函数中局部使用输入解析器。
class CalculatorApp {
public:
    CalculatorApp();
    ~CalculatorApp();

    // 拷贝控制：总入口类持有资源所有权，且业务上应为单一协调者。
    CalculatorApp(const CalculatorApp&) = delete;
    CalculatorApp& operator=(const CalculatorApp&) = delete;

    void runInteractive();
    int runCommandLine(int argc, char* argv[]);

private:
    explicit CalculatorApp(const char* version);

    void processCommand(const std::string& cmd, int a, int b);

    // 组合关系：CalculatorApp 拥有这些对象，并负责其生命周期。
    ArithmeticEngine* m_engine;
    StatisticsManager* m_stats;

    static const char* VERSION;
};

#endif
