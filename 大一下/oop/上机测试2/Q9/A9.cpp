#include <iostream>
using namespace std;

class Demo
{
public:
    static Demo& GetInstance()
    {
        static Demo instance;
        return instance;
    }
    void Addvalue(int value){mNum+=value;}
    void ShowValue()const{cout<<"Value="<<mNum<<endl;}
private:
    Demo(){mNum=0;}
    int mNum;
};

int main()
{
    Demo& demo1=Demo::GetInstance();
    Demo& demo2=Demo::GetInstance();
    demo1.Addvalue(5);
    demo2.Addvalue(10);
    demo1.ShowValue();
    demo2.ShowValue();
    return 0;
}