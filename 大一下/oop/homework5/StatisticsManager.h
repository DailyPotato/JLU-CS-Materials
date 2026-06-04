#ifndef STATISTICS_MANAGER_H
#define STATISTICS_MANAGER_H

// 统计管理类：只负责维护各类运算次数。
// 不执行计算，不解析输入，也不负责程序流程控制。
class StatisticsManager {
public:
    StatisticsManager();
    explicit StatisticsManager(int initCount);
    ~StatisticsManager();

    // 拷贝控制：统计管理器应保持唯一，拷贝会导致计数分裂混乱。
    StatisticsManager(const StatisticsManager&) = delete;
    StatisticsManager& operator=(const StatisticsManager&) = delete;

    // 内联实现：计数器自增逻辑简单，适合直接在类内实现。
    void incAdd() { ++m_addCnt; }
    void incSub() { ++m_subCnt; }
    void incMul() { ++m_mulCnt; }
    void incDiv() { ++m_divCnt; }
    void incMod() { ++m_modCnt; }
    void incRect() { ++m_rectCnt; }
    void incTri() { ++m_triCnt; }

    void printStats() const;
    void resetStats();

private:
    int m_addCnt;
    int m_subCnt;
    int m_mulCnt;
    int m_divCnt;
    int m_modCnt;
    int m_rectCnt;
    int m_triCnt;
};

#endif
