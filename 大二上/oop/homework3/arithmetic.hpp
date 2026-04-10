# ifndef ARITHMETIC_HPP
# define ARITHMETIC_HPP

extern int add_count;
extern int sub_count;
extern int mul_count;

enum ArithmeticOp{ADD,SUB,MUL};

int add(int a,int b);
int subtract(int a,int b);
int multiply(int a,int b);
ArithmeticOp getArithmeticOp(char* op);

using ArithmeticFunc = int(*)(int, int);
extern ArithmeticFunc arithmeticFuncs[];

# endif