#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H

#include "IOutput.h"

// ConsoleOutput 是一种 IOutput，公有继承表达 is-a 关系。
class ConsoleOutput : public IOutput {
public:
    ConsoleOutput();
    ~ConsoleOutput() override;

    ConsoleOutput(const ConsoleOutput&) = delete; // 无状态输出对象无需拷贝。
    ConsoleOutput& operator=(const ConsoleOutput&) = delete; // 禁止赋值保持输出策略唯一。

    void print(const std::string& msg) const override;
    void saveStats(const StatisticsManager& stats) const override;
};

#endif
