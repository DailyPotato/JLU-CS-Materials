#include <iostream>
using namespace std;

class Integer
{
public:
    Integer(int v=0):value(v)
    {
        cout<<"parameterized constructor called"<<endl;
        cout<<"initialize value to "<<v<<endl;
    }
    Integer(const Integer &other):value(other.value)
    {
        cout<<"copy constructor called"<<endl;
    }
    int getValue()
    {
        return value;
    }
    void setValue(int v)
    {
        value = v;
    }
    Integer& add(Integer other)
    {
        value += other.value;
        return *this;
    }
    Integer& subtract(Integer other)
    {
        value -= other.value;
        return *this;
    }
    Integer& multiply(Integer other)
    {
        value *= other.value;
        return *this;
    }
private:
    int value;
};

int main()
{
    Integer obj1(10);
    Integer obj2(20);
    obj1.add(obj2);
    cout<<"Value of obj1 after addition: "<<obj1.getValue()<<endl;
    obj1.subtract(obj2);
    cout<<"Value of obj1 after subtraction: "<<obj1.getValue()<<endl;
    obj1.multiply(obj2);
    cout<<"Value of obj1 after multiplication: "<<obj1.getValue()<<endl;
    Integer obj4(4);
    Integer obj5(5);
    Integer obj6(6);
    Integer obj7(7);
    Integer obj8(8);
    Integer ans{};
    cout<<"Value of ans: "<<ans.add(obj4.multiply(obj5).multiply(obj5).multiply(obj5)).add(obj6.multiply(obj5).multiply(obj5)).add(obj7.multiply(obj5)).add(obj8).getValue()<<endl;
    return 0;
}