# ifndef UTILS_H
# define UTILS_H
//使用函数重载
void printSeparator(int length, char ch='-');//使用默认参数
void printSeparator(char ch='-');//使用默认参数
void printStatistics(const int& addCount, const int& subCount, const int& mulCount, const int& divCount, const int& rectCount, const int& triCount);

# endif