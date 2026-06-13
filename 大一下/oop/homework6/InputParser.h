#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>

// 输入解析类：保留原有公共接口，用于保持旧作业结构完整。
// homework6 的新增 circle/copy/--output 解析在 CalculatorApp 中做最小必要扩展。
class InputParser {
public:
    InputParser();
    ~InputParser();

    // 拷贝控制：无状态工具类，拷贝无业务意义，因此禁止拷贝。
    // 如果此类未来成为基类且允许拷贝，派生类拷贝时应显式处理基类部分。
    InputParser(const InputParser&) = delete; // 无状态解析工具不需要复制。
    InputParser& operator=(const InputParser&) = delete; // 禁止赋值保持对象语义简单。

    bool parseCommandLine(int argc, char* argv[],
                          std::string& outCmd, int& outA, int& outB);
    bool parseInteractiveLine(const std::string& line,
                              std::string& outCmd, int& outA, int& outB);
};

#endif
