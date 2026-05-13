#include <iostream>
using namespace std;
class A
{
    public:
    A()
    {
        cout<<"create A"<<endl;
    }
    int num;
    int *p;
};
class B
{
    public:
    A a[10];
    A* pa[10];
};

int main()
{
    B b;
    for(int i=0;i<10;i++)
    {
        cout<<b.a[i].num<<endl;
    }
    return 0;
}