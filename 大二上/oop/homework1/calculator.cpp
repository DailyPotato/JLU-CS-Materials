#include <iostream>
#include <string>

using namespace std;

int _dowildcard = 0;

class calculator
{
    public:
        virtual int getResult(int ,int )=0;
};

class addCalculator:public calculator
{
    public:
        int getResult(int a,int b);
};

class subtractCalculator:public calculator
{
    public:
        int getResult(int a,int b);
};

class multiplyCalculator:public calculator
{
    public:
        int getResult(int a,int b);
};
int main(int argc, char const *argv[])
{
    if(argc!=1&&argc!=4)
    {
        cout<<"Usage: ./calculator OR ./calculator [num1][+-*][num2]"<<endl;
    }
    int num1,num2;
    if(argc==1)
    {
        cout<<"Simple Calculator"<<endl;
        cout<<"Enter first number: ";
        cin>>num1;
        cout<<"Enter second number: ";
        cin>>num2;
        cout<<num1<<" + "<<num2<<" = "<<addCalculator().getResult(num1,num2)<<endl;
        cout<<num1<<" - "<<num2<<" = "<<subtractCalculator().getResult(num1,num2)<<endl;
        cout<<num1<<" * "<<num2<<" = "<<multiplyCalculator().getResult(num1,num2);
    }
    if(argc==4)
    {
        num1=stoi(argv[1]);
        num2=stoi(argv[3]);
        string op=argv[2];
        if(op=="+")
        {
            cout<<num1<<" + "<<num2<<" = "<<addCalculator().getResult(num1,num2);
        }
        else if(op=="-")
        {
            cout<<num1<<" - "<<num2<<" = "<<subtractCalculator().getResult(num1,num2);
        }
        else if(op=="*")
        {
            cout<<num1<<" * "<<num2<<" = "<<multiplyCalculator().getResult(num1,num2);
        }
        else
        {
            cout<<"Error:Invalid operator.Use + ,- ,or * "<<endl;
        }
    }
    return 0;
}

int addCalculator::getResult(int a,int b)
{
    return a+b;
}

int subtractCalculator::getResult(int a,int b)
{
    return a-b;
}

int multiplyCalculator::getResult(int a,int b)
{
    return a*b;
}