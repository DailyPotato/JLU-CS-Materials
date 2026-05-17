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
    int getValue()
    {
        return value;
    }
    void setValue(int v)
    {
        value = v;
    }
private:
    int value;
};

int main()
{
    Integer obj;
    Integer obj2(10);
    cout<<"Value of obj: "<<obj.getValue()<<endl;
    obj.setValue(5);
    cout<<"Value of obj after setting to 5: "<<obj.getValue()<<endl;
    return 0;
}