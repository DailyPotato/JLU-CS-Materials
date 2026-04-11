# include "arithmetic.hpp"
# include <iostream>
static int add_count = 0;
static int sub_count = 0;
static int mul_count = 0;
static int div_count = 0;
auto ariOp_count=sizeof(arithmeticFuncs)/sizeof(ArithmeticFunc);
auto pADD = add;
auto pSUB = subtract;
auto pMUL = multiply;
auto pDIV = divide;
ArithmeticFunc arithmeticFuncs[] = {pADD, pSUB, pMUL, pDIV};
int add(int a,int b)
{
    return a+b;
}

int subtract(int a,int b)
{
    return a-b;
}

int multiply(int a,int b)
{
    return a*b;
}

int divide(int a,int b)
{
    if(b==0)
    {
        std::cout<<"Error: Division by zero"<<std::endl;
        return 0;
    }
    return a/b;
}

int absDifference(int a, int b)
{
    return std::abs(a - b);
}

int& getAddCount()
{
    return add_count;
}

int& getSubCount()
{
    return sub_count;
}

int& getMulCount()
{
    return mul_count;
}

int& getDivCount()
{
    return div_count;
}

const int& getAddCountReadOnly()
{
    return add_count;
}

const int& getSubCountReadOnly()
{
    return sub_count;
}

const int& getMulCountReadOnly()
{
    return mul_count;
}

const int& getDivCountReadOnly()
{
    return div_count;
}

ArithmeticOp getArithmeticOp(char* op)
{
    if(op[0]=='+')
        return ADD;
    else if(op[0]=='-')
        return SUB;
    else if(op[0]=='*')
        return MUL;
    else if(op[0]=='/')
        return DIV;
}