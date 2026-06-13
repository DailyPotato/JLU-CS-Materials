#include "ConsoleOutput.h"

#include <iostream>

ConsoleOutput::ConsoleOutput()
{
}

ConsoleOutput::~ConsoleOutput()
{
}

void ConsoleOutput::print(const std::string& msg) const
{
    std::cout << msg << std::endl;
}

void ConsoleOutput::saveStats(const StatisticsManager& stats) const
{
    stats.printStats();
}
