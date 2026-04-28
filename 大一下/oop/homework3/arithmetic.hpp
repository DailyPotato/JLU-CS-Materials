# ifndef ARITHMETIC_HPP
# define ARITHMETIC_HPP
//使用枚举类型
enum ArithmeticOp{ADD,SUB,MUL,DIV,OTHERS};

int add(const int& a, const int& b);
int subtract(const int& a, const int& b);
int multiply(const int& a, const int& b);
int divide(const int& a, const int& b);
int& getAddCount();
int& getSubCount();
int& getMulCount();
int& getDivCount();
const int& getAddCountReadOnly();
const int& getSubCountReadOnly();
const int& getMulCountReadOnly();
const int& getDivCountReadOnly();
ArithmeticOp getArithmeticOp(char* op);
//使用类型别名
//使用decltype推导函数类型
using ArithmeticFunc = decltype(add)*;
extern ArithmeticFunc arithmeticFuncs[];

# endif