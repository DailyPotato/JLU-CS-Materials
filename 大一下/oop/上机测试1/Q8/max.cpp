#include <iostream>

// int max(int a,int b)//等价于int max(const int a,const int b)
// {
//     return a>b?a:b;
// }
// const int max(int a,int b)//在使用内置类型的时候等价于返回非const类型
// {
//     return a>b?a:b;
// }
// int max(int &a,int &b)
// {
//     return a>b?a:b;
// }
int& max(int &a,int &b)
{
    return a>b?a:b;
}
// int& max(const int &a,const int &b)//const限定符被丢弃
// {
//     return a>b?a:b;
// }
// const int& max(int& a,int& b)
// {
//     return a>b?a:b;
// }
const int& max(const int& a,const int& b)
{
    return a>b?a:b;
}

int main()
{
    int retValue01=max(1,2);
    int a=3,b=4;
    int retValue02=max(a,b);
//  max(a,3)=5;表达式必须是可修改的左值
    int c=5,d=6;
    max(a,b)=max(c,d);
    return 0;
}