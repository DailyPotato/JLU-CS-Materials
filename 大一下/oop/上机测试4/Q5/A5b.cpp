#include <iostream>
using namespace std;

class A
{
public:
    A(int num) : mData(num) {}
    ~A() {}
    int GetData() const { return mData; }
    void SetData(int num) { mData = num; }

private:
    int mData;
};

class B
{
public:
    B(int num = 0) : pa(new A(num)), use(new int(1)) {}
    ~B()
    {
        ReleaseRef();
    }
    B(const B &rhs)
    {
        pa = rhs.pa;
        use = rhs.use;
        AddRef();
    }
    B &operator=(const B &rhs)
    {
        if (this != &rhs)
        {
            ReleaseRef();
            pa = rhs.pa;
            use = rhs.use;
            AddRef();
        }
        return *this;
    }
    void ReleaseRef()
    {
        if (--(*use) == 0)
        {
            delete pa;
            delete use;
            pa = nullptr;
            use = nullptr;
        }
    }
    void AddRef()
    {
        (*use)++;
    }
    A *operator->() const { return pa; }
    int GetData() const { return pa->GetData(); }
    void SetData(int data)
    {
        if (*use > 1)
        {
            (*use)--;
            pa = new A(*pa);
            use = new int(1);
        }
        pa->SetData(data);
    }
    void showUse()
    {
        cout << *use << endl;
    }

private:
    A *pa;
    int *use;
};

int main()
{
    B b1;
    B b2(b1);
    B b3 = b2;
    b1.showUse();
    b2.showUse();
    b3.showUse();
    return 0;
}