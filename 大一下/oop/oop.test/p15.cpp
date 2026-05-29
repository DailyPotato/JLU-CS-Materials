#include<iostream>

using namespace std;

class A;

class B
{
public:
    B(int num) : data(num), a(*new A(num)) {}
private:
    int data;
    A& a;
};

class A
{
public:

private:
    int data;
};

int main()
{
    B(10);
    return 0;
}