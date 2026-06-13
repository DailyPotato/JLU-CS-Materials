#include "FileOutput.h"

#include <fstream>
#include <iostream>

namespace {
const char* STATS_FILE = "stats.txt";

void writeStats(std::ostream& os, const StatisticsManager& stats)
{
    os << "--- Statistics ---" << std::endl;
    os << "circle: " << stats.getCircleCount() << " times" << std::endl;
    os << "rectangle: " << stats.getRectCount() << " times" << std::endl;
    os << "triangle: " << stats.getTriCount() << " times" << std::endl;
    os << "add: " << stats.getAddCount() << " times" << std::endl;
    os << "subtract: " << stats.getSubCount() << " times" << std::endl;
    os << "multiply: " << stats.getMulCount() << " times" << std::endl;
    os << "divide: " << stats.getDivCount() << " times" << std::endl;
    os << "mod: " << stats.getModCount() << " times" << std::endl;
}
}

FileOutput::FileOutput()
{
    // 文件输出器创建时清空旧内容，避免本次运行混入上一次运行的结果。
    std::ofstream fout(STATS_FILE);
}

FileOutput::~FileOutput()
{
}

void FileOutput::print(const std::string& msg) const
{
    std::cout << msg << std::endl;

    // FileOutput 按接口约定把普通消息也写入固定文件。
    std::ofstream fout(STATS_FILE, std::ios::app);
    if (fout) {
        fout << msg << std::endl;
    }
}

void FileOutput::saveStats(const StatisticsManager& stats) const
{
    // 采用公有 getter 读取统计数据，避免 FileOutput 成为 StatisticsManager 友元。
    std::ofstream fout(STATS_FILE, std::ios::app);
    if (!fout) {
        std::cout << "Error: cannot open stats.txt" << std::endl;
        return;
    }

    writeStats(fout, stats);
    std::cout << "Statistics saved to stats.txt" << std::endl;
}
