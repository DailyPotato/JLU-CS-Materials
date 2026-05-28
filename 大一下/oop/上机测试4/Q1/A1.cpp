#include <iostream>
using namespace std;

class Walker
{
public:
    friend class Thief;
    Walker(int n) : money(n) {}

private:
    int money;
};

class Thief
{
public:
    Thief(int n) : money(n) {}
    void pilfer(Walker &walker)
    {
        money += walker.money;
        walker.money = 0;
    }
    void showMoney()
    {
        cout<<money;
    }
private:
    int money;
};

int main()
{
    Thief a(10);
    Walker b(100);
    a.pilfer(b);
    a.showMoney();
    return 0;
}
