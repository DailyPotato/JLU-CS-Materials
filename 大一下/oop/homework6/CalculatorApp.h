#ifndef CALCULATOR_APP_H
#define CALCULATOR_APP_H

#include <string>

class ArithmeticEngine;
class IOutput;
class Shape;
class StatisticsManager;

// 总入口类：负责协调运算、统计、输入解析、图形多态和输出多态。
class CalculatorApp {
public:
    CalculatorApp();
    ~CalculatorApp();

    // 拷贝控制：总入口类拥有动态资源，拷贝会造成双重释放和状态分裂。
    // 若未来允许继承并允许拷贝，派生类应先正确复制 CalculatorApp 的资源所有权，
    // 再复制自身成员；本题按要求删除普通拷贝。
    CalculatorApp(const CalculatorApp&) = delete; // 拥有动态资源，复制会导致双重释放风险。
    CalculatorApp& operator=(const CalculatorApp&) = delete; // 禁止赋值避免覆盖资源所有权。

    void runInteractive();
    int runCommandLine(int argc, char* argv[]);

private:
    explicit CalculatorApp(const char* version);

    bool processLine(const std::string& line);
    void processCommand(const std::string& cmd, double a, double b, int argCount);
    void processArithmetic(const std::string& cmd, int a, int b);
    void processShape(const std::string& cmd, double a, double b, int argCount);
    void processCopy();
    void setFileOutput();

    // 组合关系（水平复用）：CalculatorApp 拥有运算引擎、统计管理器、
    // 输出策略和上一次图形，并负责它们的生命周期。
    // 多态的不足在于变化维度增加时容易子类爆炸：若把图形和输出绑死成
    // ConsoleRectangle、FileRectangle、ConsoleCircle 等，图形数 * 输出数会不断膨胀。
    // 本题把“图形种类”用 Shape 继承层次表达，把“输出方式”用 IOutput 继承层次表达，
    // 再在 CalculatorApp 中组合 Shape* 与 IOutput*，新增图形或输出只需增加对应派生类。
    ArithmeticEngine* m_engine;
    StatisticsManager* m_stats;
    IOutput* m_output;
    Shape* m_lastShape;

    static const char* VERSION;
};

#endif
