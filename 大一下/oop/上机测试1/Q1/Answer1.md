2 应该使用 #define #ifdef #ifndef #endif 来防止头文件重复包含

3 头文件是对外的接口，告诉编译器有什么，cpp是实现，告诉编译器应该怎么做，头文件中常包含函数原型，类定义，使用extern修饰的变量等

4 可以写一个constants.h用来存放常量，其中实现如下：
#ifndef CONSTANTS_H
#define CONSTANTS_H

enum{WON=1,TUE,WED,THU,FRI,SAT,SUN,YEARDAYS=365};
#endif