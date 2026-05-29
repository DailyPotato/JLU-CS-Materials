#include <iostream>
using namespace std;

class A
{
public:
    A(int num) : data(num) {}
    void AFuncs()
    {
        cout << "This is A \'s public function!" << endl;
    }

protected:
    int data;
};
class B
{
public:
    B(int num) : value(num) {}
    void BFuncs()
    {
        cout << "This is B \'s public function!" << endl;
    }

protected:
    int value;
};
class C : public A, private B
{
public:
    C(int num1, int num2, int y):A(num1),B(num2),yyy(y){}
    void MyFuncs()
    {
        BFuncs();
        cout << "This function call B::BFuncs() !" << endl;
    }

private:
    int yyy;
};