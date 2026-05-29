#include <iostream>
using namespace std;
class A
{
public:
    A(int n):val(n){}
protected:
    int val;
};

class B:public A
{
public:
    B(int n):A(n)
    {
        pB=(n>0?new B(n-1):0);
    }
    ~B(){delete pB;}
    void Display()
    {
        cout<<val<<endl;
        if(pB!=0)pB->Display();
    }
private:
    B * pB;
};
int main()
{
    B b(4);
    b.Display();
    return 0;
}
/*
B b(4)调用带参构造函数，4>0,b的pB指针指向B(3),递归总共构造出四个B类对象,即B(4),B(3),B(2),B(1)
分别被前一个的B类对象的指针管理
在调用b.Display()时,会依次显示每个对象的val值
即输出:
4
3
2
1
0
*/