#include<iostream>
using namespace std;

class A
{
public:
    A(int n):num(n){Out();}
    A(const A&rhs):num(rhs.num)
    {
        Out();
    }
    void Out()
    {
        cout<<num<<endl;
    }
private:
    int num;
};

class B:public A
{
public:
    B(A&a):obj(a),A(1){}
    void Out(){obj.Out();}
private:
    A obj;
};

int main()
{
    A a(8);
    B b1(a);
    B b2(b1);
    b2.Out();
    return 0;
}

/*
调用A类构造函数,输出8
实例化B类对象时,首先调用初始化列表中的A(1)构造函数,输出1
然后调用B类的构造函数,将a对象作为参数传递给obj成员变量,调用A类的复制构造函数,输出8
实例化b2对象时,调用A类的拷贝构造函数,输出1,再调用B类的默认拷贝构造函数,将b1对象的obj成员变量复制给b2对象的obj成员变量,调用A类的复制构造函数,输出8
最后调用b2.Out()函数,输出8
最终输出结果为:
8
1
8
1
8
8
*/