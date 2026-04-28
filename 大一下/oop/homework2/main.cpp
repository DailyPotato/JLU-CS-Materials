#include "arithmetic.hpp"
#include "geometry.hpp"
#include "utils.hpp"
#include "constants.hpp"
#include <iostream>
#include <cstdio>
#include <string>

int _dowildcard = 0;

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
        cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
        cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
        cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
        cout << "Rectangle area (" << num1 << "x" << num2 << ") = ";
        printf("%.2f\n", rectangleArea(num1, num2));
        cout << "Triangle area (base " << num1 << ", height " << num2 << ") = ";
        printf("%.2f\n", triangleArea(num1, num2));
        printSeparator();
    }
    else if (argc == 4)
    {
        std::string op = argv[1];
        if (op == "rectangle")
        {
            int num1, num2;
            num1 = std::stoi(argv[2]);
            num2 = std::stoi(argv[3]);
            cout << "Rectangle area (" << num1 << "x" << num2 << ") = ";
            printf("%.2f\n", rectangleArea(num1, num2));
        }
        else if (op == "triangle")
        {
            int num1, num2;
            num1 = std::stoi(argv[2]);
            num2 = std::stoi(argv[3]);
            cout << "Triangle area (base " << num1 << ", height " << num2 << ") = ";
            printf("%.2f\n", triangleArea(num1, num2));
        }
        else
        {
            int num1, num2;
            num1 = std::stoi(argv[1]);
            num2 = std::stoi(argv[3]);
            op = argv[2];
            if (op == "+")
            {
                cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
            }
            else if (op == "-")
            {
                cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
            }
            else
            {
                cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
            }
        }
    }
    else if (argc != 0 && argc != 4)
    {
        cout << "Usage: " <<endl;
        cout << "Interactive: calculator" << endl;
        cout << "Arithmetic: calculator [num1] [+-*] [num2]" << endl;
        cout << "Geometry: calculator [rectangle|triangle] [num1] [num2]";
        return 0;
    }
    printStatistics(add_count, sub_count, mul_count, rect_count, tri_count);
    return 0;
}