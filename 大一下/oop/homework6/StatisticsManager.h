#ifndef STATISTICS_MANAGER_H
#define STATISTICS_MANAGER_H

// 统计管理类：只负责维护各类运算次数。
// 为 FileOutput 写文件新增 getter，不改变原有统计流程。
class StatisticsManager {
public:
    StatisticsManager();
    explicit StatisticsManager(int initCount);
    ~StatisticsManager();

    // 拷贝控制：统计管理器应保持唯一，拷贝会导致计数分裂混乱。
    // 若它作为可继承基类且允许拷贝，拷贝构造/赋值应至少为 protected，
    // 使派生类能正确完成继承链上的拷贝；本题要求禁止拷贝。
    StatisticsManager(const StatisticsManager&) = delete; // 统计器唯一，复制会让次数统计分叉。
    StatisticsManager& operator=(const StatisticsManager&) = delete; // 禁止赋值避免覆盖正在累计的统计状态。

    void incAdd() { ++m_addCnt; }
    void incSub() { ++m_subCnt; }
    void incMul() { ++m_mulCnt; }
    void incDiv() { ++m_divCnt; }
    void incMod() { ++m_modCnt; }
    void incRect() { ++m_rectCnt; }
    void incTri() { ++m_triCnt; }
    void incCircle() { ++m_circleCnt; }

    int getAddCount() const { return m_addCnt; }
    int getSubCount() const { return m_subCnt; }
    int getMulCount() const { return m_mulCnt; }
    int getDivCount() const { return m_divCnt; }
    int getModCount() const { return m_modCnt; }
    int getRectCount() const { return m_rectCnt; }
    int getTriCount() const { return m_triCnt; }
    int getCircleCount() const { return m_circleCnt; }

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
    int m_circleCnt;
};

#endif
