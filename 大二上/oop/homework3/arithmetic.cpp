# include "arithmetic.hpp"

int add_count = 0;
int sub_count = 0;
int mul_count = 0;


ArithmeticFunc arithmeticFuncs[] = {add, subtract, multiply};
int add(int a,int b)
{
    add_count++;
    return a+b;
}

int subtract(int a,int b)
{
    sub_count++;
    return a-b;
}

int multiply(int a,int b)
{
    mul_count++;
    return a*b;
}

ArithmeticOp getArithmeticOp(char* op)
{
    if(op[0]=='+')
        return ADD;
    else if(op[0]=='-')
        return SUB;
    else if(op[0]=='*')
        return MUL;
}