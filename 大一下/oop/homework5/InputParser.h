#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>

// 输入解析类：无状态工具类，只负责校验输入并转换为命令和两个操作数。
class InputParser {
public:
    InputParser();
    ~InputParser();

    // 拷贝控制：无状态工具类，拷贝无业务意义，因此禁止拷贝。
    InputParser(const InputParser&) = delete;
    InputParser& operator=(const InputParser&) = delete;

    bool parseCommandLine(int argc, char* argv[],
                          std::string& outCmd, int& outA, int& outB);
    bool parseInteractiveLine(const std::string& line,
                              std::string& outCmd, int& outA, int& outB);
};

#endif
