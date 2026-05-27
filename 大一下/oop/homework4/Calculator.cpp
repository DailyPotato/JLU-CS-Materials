#include "Calculator.h"

string Calculator::Version = "v1.0";
int Calculator::defaultDividerLenth = 30;
int Calculator::MAX_CAL_NUM = 1000000;
bool Calculator::isValidNumber(const std::string &str)
{
    if (str.empty())
        return false;
    try
    {
        size_t parsed_chars = 0;
        std::stod(str, &parsed_chars);
        return parsed_chars == str.length();
    }
    catch (...)
    {
        return false;
    }
}
double Calculator::add(double a, double b)
{
    addCount++;
    if((a+b)>MAX_CAL_NUM)
    {
        cout << "Error: Result exceeds maximum value ( " << MAX_CAL_NUM << " )." << endl;
        return -1;
    }
    return a + b;
}

double Calculator::sub(double a, double b)
{
    subCount++;
    return a - b;
}

double Calculator::mul(double a, double b)
{
    mulCount++;
    if((a*b)>MAX_CAL_NUM)
    {
        cout << "Error: Result exceeds maximum value ( " << MAX_CAL_NUM << " )." << endl;
        return -1;
    }
    return a * b;
}

double Calculator::div(double a, double b)
{
    divCount++;
    if (b == 0)
    {
        cout << "Error: Division by zero." << endl;
        return -1;
    }
    if((a/b)>MAX_CAL_NUM)
    {
        cout << "Error: Result exceeds maximum value ( " << MAX_CAL_NUM << " )." << endl;
        return -1;
    }
    return a / b;
}

double Calculator::mod(double a, double b)
{
    modCount++;
    return static_cast<int>(a) % static_cast<int>(b);
}

double Calculator::areaOfRectangle(double length, double width)
{
    areaOfRectangleCount++;
    if (length < 0 || width < 0)
    {
        cout << "Error: Length and width must be positive." << endl;
        return -1;
    }
    if((length*width)>MAX_CAL_NUM)
    {
        cout << "Error: Result exceeds maximum value ( " << MAX_CAL_NUM << " )." << endl;
        return -1;
    }
    return length * width;
}

double Calculator::areaOfTriangle(double base, double height)
{
    areaOfTriangleCount++;
    if (base < 0 || height < 0)
    {
        cout << "Error: base and height must be non-negative!" << endl;
        return -1;
    }
    if((0.5*base*height)>MAX_CAL_NUM)
    {
        cout << "Error: Result exceeds maximum value ( " << MAX_CAL_NUM << " )." << endl;
        return -1;
    }
    return 0.5 * base * height;
}

void Calculator::printVersion()
{
    cout << "Calculator version: " << Version << endl;
}

void Calculator::printHelp()
{
    printVersion();
    cout << "max num=" << MAX_CAL_NUM << endl;
    cout << "default divider length=" << defaultDividerLenth << endl;
}

void Calculator::runInteractive()
{
    cout << "Useage: " << endl;
    cout << "arithmatic calculate format: [num1] [ + | - | * | / | % ] [num2]" << endl;
    cout << "geometry calculate format: [rectangle|triangle] [num1] [num2]" << endl;
    while (true)
    {
        string op;
        cin >> op;
        if (op == "exit")
        {
            return;
        }
        else if (op == "rectangle" || op == "triangle")
        {
            double num1, num2;
            cin >> num1 >> num2;
            if (!isLessThanMaxCalNum(num1) || !isLessThanMaxCalNum(num2))
            {
                cout << "Error: Number exceeds maximum value ( " << MAX_CAL_NUM << " )." << endl;
                continue;
            }
            if (op == "rectangle")
            {
                cout << "Area of rectangle: " << areaOfRectangle(num1, num2) << endl;
            }
            else
            {
                cout << "Area of triangle: " << areaOfTriangle(num1, num2) << endl;
            }
        }
        else if (isValidNumber(op))
        {
            double num1 = stod(op);
            cin >> op;
            double num2;
            cin >> num2;
            if (!isLessThanMaxCalNum(num1) || !isLessThanMaxCalNum(num2))
            {
                cout << "Error: Number exceeds maximum value ( " << MAX_CAL_NUM << " )." << endl;
                continue;
            }
            if (op == "+")
            {
                cout << "Result: " << add(num1, num2) << endl;
            }
            else if (op == "-")
            {
                cout << "Result: " << sub(num1, num2) << endl;
            }
            else if (op == "*")
            {
                cout << "Result: " << mul(num1, num2) << endl;
            }
            else if (op == "/")
            {
                cout << "Result: " << div(num1, num2) << endl;
            }
            else if (op == "%")
            {
                cout << "Result: " << mod(num1, num2) << endl;
            }
            else
            {
                cout << "Error: Unsupported operator. Use +, -, *, /, %" << endl;
            }
        }
        else
        {
            cout << "Error: Unknown shape. Use rectangle or triangle." << endl;
        }
    }
    printStats();
    return;
}
