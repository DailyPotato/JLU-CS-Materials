#include <iostream>
using namespace std;

class Integer
{
public:
    Integer():value(0)
    {
        cout<<"default constructor called"<<endl;
        cout<<"initialize value to 0"<<endl;
    }
    Integer(const Integer &other):value(other.value)
    {
        cout<<"copy constructor called"<<endl;
    }
    void setValue(int v)
    {
        value = v;
    }
    int isGreater_value(Integer other) const 
    {
        cout<<"Value"<<endl;
        if (this->value > other.value) return 1;
        if (this->value == other.value) return 0;
        return -1;
    }
    int isGreater_reference(Integer &other) const 
    {
        cout<<"Reference"<<endl;
        if (this->value > other.value) return 1;
        if (this->value == other.value) return 0;
        return -1;
    }
private:
    int value;
};

int main()
{
    Integer obj;
    Integer obj2(obj);
    obj2.setValue(10);
    cout<<"Comparing obj and obj2 by value: "<<obj.isGreater_value(obj2)<<endl;
    cout<<"Comparing obj and obj2 by reference: "<<obj.isGreater_reference(obj2)<<endl;
    return 0;
}