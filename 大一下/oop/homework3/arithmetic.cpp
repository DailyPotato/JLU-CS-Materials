# include "arithmetic.hpp"
# include <iostream>
static int add_count = 0;
static int sub_count = 0;
static int mul_count = 0;
static int div_count = 0;


//auto类型推导
auto pADD = add;
auto pSUB = subtract;
auto pMUL = multiply;
auto pDIV = divide;


//使用函数指针数组
ArithmeticFunc arithmeticFuncs[] = {pADD, pSUB, pMUL, pDIV};
auto ariOp_count=sizeof(arithmeticFuncs)/sizeof(ArithmeticFunc);

//引用形参与引用返回值综合
int add(const int& a, const int& b)
{
    return a+b;
}

int subtract(const int& a, const int& b)
{
    return a-b;
}

int multiply(const int& a, const int& b)
{
    return a*b;
}


// 选做扩展内容：整数除法DIV运算
int divide(const int& a, const int& b)
{
    if(b==0)
    {
        //除数为0，输出错误信息并返回0
        std::cout<<"Error: Division by zero"<<std::endl;
        exit(0);
    }
    return a/b;
}


//选做扩展内容：绝对值差
int absDifference(const int& a, const int& b)
{
    return std::abs(a - b);
}


//返回值为引用的函数
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
    else
        return OTHERS;//默认返回加法，实际使用时会根据输入进行判断
}