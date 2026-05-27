#include <iostream>
using namespace std;

class A
{
public:
    A(int n):data(n){}
    int Data()const{return data;}
private:
    int data;
};

void g(int n)
{
    A** arr=new A*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new A(i+1);
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]->Data()<<endl;
    }
    for(int i=0;i<n;i++)
    {
        delete arr[i];
    }
    delete[] arr;
}

int main()
{
    int n;
    cin>>n;
    g(n);
    return 0;
}