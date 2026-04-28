#include "arithmetic.hpp"
#include "geometry.hpp"
#include "utils.hpp"
#include "constants.hpp"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
int _dowildcard = 0;
//声明回调函数
int executeArithmetic(ArithmeticFunc callback, int a, int b, ArithmeticOp op);
double executeGeometry(GeometryFunc callback, const double &a, const double &b, GeometryShape shape);
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
    if (argc == 1)
    {
        int num1, num2;
        cout << "Multi-Module Calculator v";
        printf("%.1f\n", PROGRAM_VERSION);
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << num1 << " + " << num2 << " = " << executeArithmetic(add, num1, num2, ADD) << endl;
        cout << num1 << " - " << num2 << " = " << executeArithmetic(subtract, num1, num2, SUB) << endl;
        cout << num1 << " * " << num2 << " = " << executeArithmetic(multiply, num1, num2, MUL) << endl;
        cout << num1 << " / " << num2 << " = " << executeArithmetic(divide, num1, num2, DIV) << endl;
        // 边长为负数的情况，输出错误信息并返回0
        if (num1 <= 0 || num2 <= 0)
        {
            cout << "Error: Both numbers must be positive for geometry calculations." << endl;
            return 0;
        }
        cout << "Rectangle area (" << num1 << "x" << num2 << ") = ";
        printf("%.2f\n", executeGeometry(rectangleArea, num1, num2, RECTANGLE));
        cout << "Triangle area (base " << num1 << ", height " << num2 << ") = ";
        printf("%.2f\n", executeGeometry(triangleArea, num1, num2, TRIANGLE));
        printSeparator();
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "rectangle") == 0 || strcmp(argv[1], "triangle") == 0)
        {
            GeometryShape Geoop = getGeometryOp((char *)argv[1]);
            auto num1 = std::stoi(argv[2]);
            auto num2 = std::stoi(argv[3]);
            if (num1 <= 0 || num2 <= 0)
            {
                cout << "Error: Both numbers must be positive for geometry calculations." << endl;
                return 0;
            }
            if (Geoop == RECTANGLE)
            {
                cout << "Rectangle area (" << num1 << "x" << num2 << ") = ";
                printf("%.2f\n", executeGeometry(rectangleArea, num1, num2, RECTANGLE));
            }
            else if (Geoop == TRIANGLE)
            {
                cout << "Triangle area (base " << num1 << ", height " << num2 << ") = ";
                printf("%.2f\n", executeGeometry(triangleArea, num1, num2, TRIANGLE));
            }
        }
        else if (isdigit(argv[2][0]) && isdigit(argv[3][0]))
        {
            cout << "Invalid operator. Supported operators are: +, -, *, /, rectangle, triangle." << endl;
            return 0;
        }
        else
        {
            auto num1 = std::stoi(argv[1]);
            auto num2 = std::stoi(argv[3]);
            ArithmeticOp Ariop = getArithmeticOp((char *)argv[2]);
            if (Ariop == ADD)
            {
                cout << num1 << " + " << num2 << " = " << executeArithmetic(add, num1, num2, ADD) << endl;
            }
            else if (Ariop == SUB)
            {
                cout << num1 << " - " << num2 << " = " << executeArithmetic(subtract, num1, num2, SUB) << endl;
            }
            else if (Ariop == MUL)
            {
                cout << num1 << " * " << num2 << " = " << executeArithmetic(multiply, num1, num2, MUL) << endl;
            }
            else if (Ariop == DIV)
            {
                cout << num1 << " / " << num2 << " = " << executeArithmetic(divide, num1, num2, DIV) << endl;
            }
            else
            {
                // 无效的运算符，输出错误信息并返回0
                cout << "Invalid operator. Supported operators are: +, -, *, /, rectangle, triangle." << endl;
                return 0;
            }
        }
    }
    else if (argc != 0 && argc != 4)
    {
        cout << "Usage: " << endl;
        cout << "Interactive: calculator" << endl;
        cout << "Arithmetic: calculator [num1] [+-*/] [num2]" << endl;
        cout << "Geometry: calculator [rectangle|triangle] [num1] [num2]";
        return 0;
    }
    printStatistics(getAddCountReadOnly(), getSubCountReadOnly(), getMulCountReadOnly(), getDivCountReadOnly(), getRectCountReadOnly(), getTriCountReadOnly());
    return 0;
}
//定义算术回调函数
int executeArithmetic(const ArithmeticFunc callback, int a, int b, ArithmeticOp op)
{
    //使用const指针参数，确保回调函数不会修改传入的参数
    if (callback == nullptr)
    {
        cout << "Invalid arithmetic function." << endl;
        return 0;
    }
    switch (op)
    {
    case ADD:
        getAddCount()++;
        break;
    case SUB:
        getSubCount()++;
        break;
    case MUL:
        getMulCount()++;
        break;
    case DIV:
        if (b != 0)
        {
            getDivCount()++;
        }
        break;
    }
    return callback(a, b);
}
//定义几何回调函数
double executeGeometry(const GeometryFunc callback, const double &a, const double &b, GeometryShape shape)
{
    //使用const引用参数，确保回调函数不会修改传入的参数
    if (callback == nullptr)
    {
        cout << "Invalid geometry function." << endl;
        return 0;
    }
    switch (shape)
    {
    case RECTANGLE:
        getRectCount()++;
        break;
    case TRIANGLE:
        getTriCount()++;
        break;
    }
    return callback(a, b);
}