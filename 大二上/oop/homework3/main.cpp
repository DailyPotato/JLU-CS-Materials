#include "arithmetic.hpp"
#include "geometry.hpp"
#include "utils.hpp"
#include "constants.hpp"
#include <iostream>
#include <cstdio>
#include <string>

int _dowildcard = 0;

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
        if(num1<=0||num2<=0)
        {
            cout<<"Error: Both numbers must be positive for geometry calculations."<<endl;
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
        GeometryShape Geoop = getGeometryOp((char *)argv[1]);
        if (Geoop == RECTANGLE)
        {
            auto num1 = std::stoi(argv[2]);
            auto num2 = std::stoi(argv[3]);
            cout << "Rectangle area (" << num1 << "x" << num2 << ") = ";
            printf("%.2f\n", executeGeometry(rectangleArea, num1, num2, RECTANGLE));
        }
        else if (Geoop == TRIANGLE)
        {
            auto num1 = std::stoi(argv[2]);
            auto num2 = std::stoi(argv[3]);
            cout << "Triangle area (base " << num1 << ", height " << num2 << ") = ";
            printf("%.2f\n", executeGeometry(triangleArea, num1, num2, TRIANGLE));
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
                cout << "Invalid operator. Supported operators are: +, -, *, /, rectangle, triangle." << endl;
                return 0;
            }
        }
    }
    else if (argc != 0 && argc != 4)
    {
        cout << "Usage: " << endl;
        cout << "Interactive: calculator" << endl;
        cout << "Arithmetic: calculator [num1] [+-*] [num2]" << endl;
        cout << "Geometry: calculator [rectangle|triangle] [num1] [num2]";
        return 0;
    }
    printStatistics(getAddCount(), getSubCount(), getMulCount(), getDivCount(), getRectCount(), getTriCount());
    return 0;
}

int executeArithmetic(const ArithmeticFunc callback, int a, int b, ArithmeticOp op)
{
    if (callback == nullptr)
    {
        cout << "错误" << endl;
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
double executeGeometry(const GeometryFunc callback, const double &a, const double &b, GeometryShape shape)
{
    if (callback == nullptr)
    {
        cout << "错误" << endl;
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