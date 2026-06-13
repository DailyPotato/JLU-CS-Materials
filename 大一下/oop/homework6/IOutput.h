#ifndef IOUTPUT_H
#define IOUTPUT_H

#include <string>

#include "StatisticsManager.h"

// 接口类：只包含纯虚函数，规定“输出方式”必须具备的行为。
// CalculatorApp 依赖 IOutput 抽象而非具体输出类，从而通过多态切换控制台/文件。
class IOutput {
public:
    virtual ~IOutput() = default;

    // 拷贝控制：接口对象通常由基类指针持有，拷贝会造成切片或所有权不清。
    // 若接口基类允许拷贝，派生类应正确调用基类拷贝并复制自身资源。
    IOutput(const IOutput&) = delete; // 接口基类禁止拷贝，防止输出对象切片。
    IOutput& operator=(const IOutput&) = delete; // 禁止赋值，避免只赋值接口基类部分。

    virtual void print(const std::string& msg) const = 0;
    virtual void saveStats(const StatisticsManager& stats) const = 0;

protected:
    IOutput() = default;
};

#endif
