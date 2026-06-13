#include "StatisticsManager.h"

#include <iostream>

StatisticsManager::StatisticsManager()
    : m_addCnt(0),
      m_subCnt(0),
      m_mulCnt(0),
      m_divCnt(0),
      m_modCnt(0),
      m_rectCnt(0),
      m_triCnt(0),
      m_circleCnt(0)
{
    std::cout << "StatisticsManager created" << std::endl;
}

StatisticsManager::StatisticsManager(int initCount)
    : m_addCnt(initCount),
      m_subCnt(initCount),
      m_mulCnt(initCount),
      m_divCnt(initCount),
      m_modCnt(initCount),
      m_rectCnt(initCount),
      m_triCnt(initCount),
      m_circleCnt(initCount)
{
    std::cout << "StatisticsManager created with init count: "
              << initCount << std::endl;
}

StatisticsManager::~StatisticsManager()
{
    std::cout << "StatisticsManager destroyed" << std::endl;
}

void StatisticsManager::printStats() const
{
    std::cout << "--- Statistics ---" << std::endl;
    std::cout << "circle: " << m_circleCnt << " times" << std::endl;
    std::cout << "rectangle: " << m_rectCnt << " times" << std::endl;
    std::cout << "triangle: " << m_triCnt << " times" << std::endl;
    std::cout << "add: " << m_addCnt << " times" << std::endl;
    std::cout << "subtract: " << m_subCnt << " times" << std::endl;
    std::cout << "multiply: " << m_mulCnt << " times" << std::endl;
    std::cout << "divide: " << m_divCnt << " times" << std::endl;
    std::cout << "mod: " << m_modCnt << " times" << std::endl;
}

void StatisticsManager::resetStats()
{
    m_addCnt = 0;
    m_subCnt = 0;
    m_mulCnt = 0;
    m_divCnt = 0;
    m_modCnt = 0;
    m_rectCnt = 0;
    m_triCnt = 0;
    m_circleCnt = 0;
}
