# ifndef ARITHMETIC_HPP
# define ARITHMETIC_HPP

// extern int add_count;
// extern int sub_count;
// extern int mul_count;
// extern int div_count;

enum ArithmeticOp{ADD,SUB,MUL,DIV};

int add(int a,int b);
int subtract(int a,int b);
int multiply(int a,int b);
int divide(int a,int b);
int& getAddCount();
int& getSubCount();
int& getMulCount();
int& getDivCount();
const int& getAddCountReadOnly();
const int& getSubCountReadOnly();
const int& getMulCountReadOnly();
const int& getDivCountReadOnly();
ArithmeticOp getArithmeticOp(char* op);

using ArithmeticFunc = decltype(add)*;
extern ArithmeticFunc arithmeticFuncs[];

# endif