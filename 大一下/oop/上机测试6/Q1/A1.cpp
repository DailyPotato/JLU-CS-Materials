#include<iostream>
using namespace std;;
class A
{
public:
    A() { cout << "Lines=" << ++lineno << " Call A::A()" << endl; }
    virtual ~A() { cout << "Lines=" << ++lineno << " Call A::~A()" << endl; } //----------------(1)
    virtual int Func1() const = 0;                                            //-----------------------------------------------(2)
    virtual void Func2(int = 500) = 0;                                        //-----------------------------------------------(3)
protected:                                                                    //-------------------------------------------------------------(4)
    static int lineno;
};
class B : public A
{
public:
    B() { cout << "Lines=" << ++lineno << " Call B::B()" << endl; }
    virtual ~B() { cout << "Lines=" << ++lineno << " Call B::~B()" << endl; } //----------------(5)
    virtual int Func1(int n) const { return num + n; }
    virtual int Func1() const //--------------------------------------------(6)
    {
        cout << "Lines=" << ++lineno << " Call B::Func1() const" << endl;
        return num;
    }
    virtual void Func2(int n = 1000) //--------------------------------------------(7)
    {
        cout << "Lines=" << ++lineno << " Call B::Func2(int) const n=" << n << endl;
        num = n;
    }
    void Func3(int n) { num = n; } //---------------------------------------------(8)
protected:
    int num;
};
int A::lineno = 0; //----------------------------------------------(9)
int main(int argc, char *argv[])
{
    A *p = new B; //---------------------------------------------(10)
    p->Func2(50); //---------------------------------------------(11)
    p->Func2();   //---------------------------------------------(12)
    p->Func1();   //---------------------------------------------(13)
    // p->Func3(100); //---------------------------------------------(14)
    // p->Func1(100); //---------------------------------------------(15)
    delete p;
    return 0;
}