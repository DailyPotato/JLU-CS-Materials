#include "ArithmeticEngine.h"

#include <iostream>

const int ArithmeticEngine::MAX_VALUE = 100000;

namespace {
bool inAllowedRange(long long value)
{
    return value >= -ArithmeticEngine::MAX_VALUE
        && value <= ArithmeticEngine::MAX_VALUE;
}

bool checkResultRange(long long value)
{
    if (!inAllowedRange(value)) {
        std::cout << "Error: result out of range" << std::endl;
        return false;
    }
    return true;
}
}

ArithmeticEngine::ArithmeticEngine()
{
    std::cout << "ArithmeticEngine created" << std::endl;
}

ArithmeticEngine::~ArithmeticEngine()
{
    std::cout << "ArithmeticEngine destroyed" << std::endl;
}

int ArithmeticEngine::add(int a, int b) const
{
    // 先使用 long long 计算再检查范围，避免整数溢出后再判断。
    long long result = static_cast<long long>(a) + b;
    return checkResultRange(result) ? static_cast<int>(result) : 0;
}

int ArithmeticEngine::subtract(int a, int b) const
{
    long long result = static_cast<long long>(a) - b;
    return checkResultRange(result) ? static_cast<int>(result) : 0;
}

int ArithmeticEngine::multiply(int a, int b) const
{
    long long result = static_cast<long long>(a) * b;
    return checkResultRange(result) ? static_cast<int>(result) : 0;
}

int ArithmeticEngine::divide(int a, int b) const
{
    if (b == 0) {
        std::cout << "Error: division by zero" << std::endl;
        return 0;
    }
    return a / b;
}

int ArithmeticEngine::mod(int a, int b) const
{
    if (b == 0) {
        std::cout << "Error: modulo by zero" << std::endl;
        return 0;
    }
    return a % b;
}

double ArithmeticEngine::rectangleArea(double length, double width) const
{
    if (length <= 0 || width <= 0) {
        std::cout << "Error: side length must be positive" << std::endl;
        return 0.0;
    }
    return length * width;
}

double ArithmeticEngine::triangleArea(double base, double height) const
{
    if (base <= 0 || height <= 0) {
        std::cout << "Error: side length must be positive" << std::endl;
        return 0.0;
    }
    return base * height / 2.0;
}

void ArithmeticEngine::printLimits()
{
    std::cout << "Allowed result range: ["
              << -MAX_VALUE << ", " << MAX_VALUE << "]" << std::endl;
}
