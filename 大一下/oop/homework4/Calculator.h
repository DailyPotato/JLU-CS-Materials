#ifndef CAL
#define CAL
#include <iostream>
#include <string>
using namespace std;
class Calculator
{
public:
    // 公有接口仅暴露必要的运算、统计、运行方法
    // 带参构造函数
    explicit Calculator(int count) : addCount(count), subCount(count), mulCount(count), divCount(count), modCount(count), areaOfRectangleCount(count), areaOfTriangleCount(count)
    {
        cout << "Calculator created with init count:" << count << endl;
    }
    // 默认构造函数、委托构造
    Calculator():Calculator(0)
    {
        cout << "Calculator created" << endl;
    }
    // 析构函数
    ~Calculator()
    {
        cout << "Calculator destroyed" << endl;
    }
    // 外联实现
    double add(double a, double b);
    double sub(double a, double b);
    double mul(double a, double b);
    double div(double a, double b);
    double mod(double a, double b);
    double areaOfRectangle(double length, double width);
    double areaOfTriangle(double base, double height);
    // 内联实现
    int getAddCount() { return addCount; }
    int getSubCount() { return subCount; }
    int getMulCount() { return mulCount; }
    int getDivCount() { return divCount; }
    int getModCount() { return modCount; }
    int getAreaOfRectangleCount() { return areaOfRectangleCount; }
    int getAreaOfTriangleCount() { return areaOfTriangleCount; }
    void printStats()
    {
        cout<<"Function call statistics:"<<endl;
        cout << "add: " << addCount << "times" << endl;
        cout << "sub: " << subCount << "times" << endl;
        cout << "mul: " << mulCount << "times" << endl;
        cout << "div: " << divCount << "times" << endl;
        cout << "mod: " << modCount << "times" << endl;
        cout << "rectangle: " << areaOfRectangleCount << "times" << endl;
        cout << "triangle: " << areaOfTriangleCount << "times" << endl;
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
    // 辅助函数私有
    bool isValidNumber(const std::string &str);
    // 所有数据成员私有
    int addCount;
    int subCount;
    int mulCount;
    int divCount;
    int modCount;
    int areaOfRectangleCount;
    int areaOfTriangleCount;
    // 静态成员变量
    static string Version;
    static int defaultDividerLenth;
    static int MAX_CAL_NUM;
};

#endif