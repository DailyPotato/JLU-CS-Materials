#include<iostream>
using namespace std;

class Animal
{
public:
    Animal(string name, int weight):name(name), weight(weight){}
protected:
    void who()
    {
        cout<<"name:"<<name<<", weight:"<<weight<<endl;
    }
private:
    string name;
    int weight;
};

class Lion:public Animal
{
public:
    Lion(string n, int w):Animal(n, w){}
    void who()
    {
        cout<<"Lion - ";
        Animal::who();
    }
};

class Aardvark:public Animal
{
public:
    Aardvark(string n, int w):Animal(n, w){}
    void who()
    {
        cout<<"Aardvark - ";
        Animal::who();
    }
};

int main()
{
    Lion lion{"Leo",400};
    Aardvark aardvark{"Algernon",50};
    lion.who();
    aardvark.who();
    return 0;
}