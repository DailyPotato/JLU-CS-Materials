#ifndef CAL
#define CAL
#include <iostream>
#include <string>
using namespace std;
class Calculator
{
public:
    explicit Calculator(int count) : addCount(count), subCount(count), mulCount(count), divCount(count), modCount(count), areaOfRectangleCount(count), areaOfTriangleCount(count)
    {
        cout << "Calculator created with init count:" << count << endl;
    }
    Calculator():Calculator(0)
    {
        cout << "Calculator created" << endl;
    }
    ~Calculator()
    {
        cout << "Calculator destroyed" << endl;
    }
    double add(double a, double b);
    double sub(double a, double b);
    double mul(double a, double b);
    double div(double a, double b);
    double mod(double a, double b);
    double areaOfRectangle(double length, double width);
    double areaOfTriangle(double base, double height);

    int getAddCount() { return addCount; }
    int getSubCount() { return subCount; }
    int getMulCount() { return mulCount; }
    int getDivCount() { return divCount; }
    int getModCount() { return modCount; }
    int getAreaOfRectangleCount() { return areaOfRectangleCount; }
    int getAreaOfTriangleCount() { return areaOfTriangleCount; }
    void printStats()
    {
        cout << "Addition count: " << addCount << endl;
        cout << "Subtraction count: " << subCount << endl;
        cout << "Multiplication count: " << mulCount << endl;
        cout << "Division count: " << divCount << endl;
        cout << "Modulus count: " << modCount << endl;
        cout << "Area of rectangle count: " << areaOfRectangleCount << endl;
        cout << "Area of triangle count: " << areaOfTriangleCount << endl;
    }
    void resetStats()
    {
        addCount = 0;
        subCount = 0;
        mulCount = 0;
        divCount = 0;
        modCount = 0;
        areaOfRectangleCount = 0;
        areaOfTriangleCount = 0;
    }
    void runInteractive();
    bool isValidNumber(const std::string &str);
    bool isLessThanMaxCalNum(int num)
    {
        return num <= MAX_CAL_NUM;
    }
    static void printVersion();
    static void printHelp();
    static int getMaxCalNum() { return MAX_CAL_NUM; }

private:
    // 嵌入式场景下禁止对象拷贝，避免资源浪费和内存碎片
    Calculator(const Calculator &) = delete;
    Calculator &operator=(const Calculator &) = delete;

    int addCount;
    int subCount;
    int mulCount;
    int divCount;
    int modCount;
    int areaOfRectangleCount;
    int areaOfTriangleCount;

    static string Version;
    static int defaultDividerLenth;
    static int MAX_CAL_NUM;
};

#endif