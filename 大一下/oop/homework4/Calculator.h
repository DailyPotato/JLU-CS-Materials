#ifndef CAL
#define CAL
#include <iostream>
#include <string>
using namespace std;
class Calculator
{
public:
    Calculator():addCount(0),subCount(0),mulCount(0),divCount(0),modCount(0),areaOfRectangleCount(0),areaOfTriangleCount(0)
    {
        cout<<"Calculator created"<<endl;
    }
    double add(double a,double b);
    double sub(double a,double b);
    double mul(double a,double b);
    double div(double a,double b);
    double mod(double a,double b);
    double areaOfRectangle(double length,double width);
    double areaOfTriangle(double base,double height);

    int getAddCount(){return addCount;}
    int getSubCount(){return subCount;}
    int getMulCount(){return mulCount;}
    int getDivCount(){return divCount;}
    int getModCount(){return modCount;}
    int getAreaOfRectangleCount(){return areaOfRectangleCount;}
    int getAreaOfTriangleCount(){return areaOfTriangleCount;}

    void resetCount()
    {
        addCount=0;
        subCount=0;
        mulCount=0;
        divCount=0;
        modCount=0;
        areaOfRectangleCount=0;
        areaOfTriangleCount=0;
    }
    int runInteractive();
    static void printVersion();
    static void printHelp();
private:
//嵌入式场景下禁止对象拷贝，避免资源浪费和内存碎片
    Calculator(const Calculator&)=delete;
    Calculator& operator=(const Calculator&)=delete;

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