#include "Calculator.h"
#include <string>
#include <iomanip>
int main(int argc, char *argv[])
{
    // 匿名对象
    Calculator().printHelp();
    Calculator::printVersion();

    if (argc == 1)
    {
        // 栈对象
        Calculator calc;
        calc.runInteractive();
    }
    else if (argc >= 3)
    {
        // 动态对象
        Calculator *pCalc = new Calculator(10);
        string op = argv[1];
        if (op == "rectangle" || op == "triangle")
        {
            double num1, num2;
            try
            {
            num1 = stod(argv[2]);
            num2 = stod(argv[3]);
            }
            catch(...)
            {
                cout << "Error: Invalid number format." << endl;
                return 0;
            }
            if (!pCalc->isLessThanMaxCalNum(num1) || !pCalc->isLessThanMaxCalNum(num2))
            {
                cout << "Error: Number exceeds maximum value ( " << Calculator::getMaxCalNum() << " )." << endl;
                return 0;
            }
            if (op == "rectangle")
            {

                cout << "Rectangle area:("<< num1 << " * " << num2 << ") = " << fixed << setprecision(2) << pCalc->areaOfRectangle(num1, num2) << endl;
            }
            else
            {
                cout << "Triangle area:(base "<< num1 << ", height " << num2 << ") = " << fixed << setprecision(2) << pCalc->areaOfTriangle(num1, num2) << endl;
            }
        }
        else
        {
            double num1,num2;
            string op = argv[2];
            try
            {
                num1=stod(argv[1]);
                num2=stod(argv[3]);
            }
            catch(...)
            {
                cout << "Error: Invalid number format." << endl;
                return 0;
            }
            if (!pCalc->isLessThanMaxCalNum(num1) || !pCalc->isLessThanMaxCalNum(num2))
            {
                cout << "Error: Number exceeds maximum value ( " << Calculator::getMaxCalNum() << " )." << endl;
                return 0;
            }
            if (op == "+")
            {
                cout << "Result: " << pCalc->add(num1, num2) << endl;
            }
            else if (op == "-")
            {
                cout << "Result: " << pCalc->sub(num1, num2) << endl;
            }
            else if (op == "*")
            {
                cout << "Result: " << pCalc->mul(num1, num2) << endl;
            }
            else if (op == "/")
            {
                cout << "Result: " << pCalc->div(num1, num2) << endl;
            }
            else if (op == "%")
            {
                cout << "Result: " << pCalc->mod(num1, num2) << endl;
            }
            else
            {
                cout << "Error: Unsupported operator. Use +, -, *, /, %" << endl;
                return 0;
            }
        }
    pCalc->printStats();
    delete pCalc;
    }
    else
    {
        cout << "Error: Invalid number of arguments." << endl;
    }
    Calculator *pCalc = new Calculator();
    delete pCalc;
    return 0;
}