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
class C : public A
{
public:
    C(int num1, int num2, int y):A(num1),pB(new B(num2)),yyy(y){}
    ~C()
    {
        delete pB;
    }
    C(const C& c):A(c),pB(new B(*c.pB)),yyy(c.yyy){}
    C& operator=(const C& c)
    {
        if (this != &c)
        {
            A::operator=(c);
            *pB = *c.pB;
            yyy = c.yyy;
        }
        return *this;
    }
    void MyFuncs()
    {
        pB->BFuncs();
        cout << "This function call B::BFuncs() !" << endl;
    }

private:
    int yyy;
    B* pB;
};