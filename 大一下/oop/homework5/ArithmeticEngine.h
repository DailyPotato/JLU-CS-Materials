#ifndef ARITHMETIC_ENGINE_H
#define ARITHMETIC_ENGINE_H

// 运算引擎类：无状态工具类，只负责算术运算和几何面积计算。
// 不处理输入解析，也不维护统计信息。
class ArithmeticEngine {
public:
    // 静态成员：所有运算引擎对象共享的数值上限。
    static const int MAX_VALUE;

    ArithmeticEngine();
    ~ArithmeticEngine();

    // 拷贝控制：无状态工具类，拷贝无业务意义，因此禁止拷贝。
    ArithmeticEngine(const ArithmeticEngine&) = delete;
    ArithmeticEngine& operator=(const ArithmeticEngine&) = delete;

    int add(int a, int b) const;
    int subtract(int a, int b) const;
    int multiply(int a, int b) const;
    int divide(int a, int b) const;
    int mod(int a, int b) const;

    double rectangleArea(double length, double width) const;
    double triangleArea(double base, double height) const;

    static void printLimits();
};

#endif
