#ifndef FILE_OUTPUT_H
#define FILE_OUTPUT_H

#include "IOutput.h"

// FileOutput 是一种 IOutput，负责把消息打印到屏幕并把统计写入固定文件 stats.txt。
class FileOutput : public IOutput {
public:
    FileOutput();
    ~FileOutput() override;

    FileOutput(const FileOutput&) = delete; // 固定文件输出器不应被复制出多个所有者。
    FileOutput& operator=(const FileOutput&) = delete; // 禁止赋值避免文件输出策略被覆盖。

    void print(const std::string& msg) const override;
    void saveStats(const StatisticsManager& stats) const override;
};

#endif
