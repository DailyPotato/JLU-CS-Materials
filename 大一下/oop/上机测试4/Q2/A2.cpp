#include <iostream>
using namespace std;

class Thief;
class PoliceStation;
class Police
{
public:
    Police(int n = 0) : bonus(n) {}
    void setPS(PoliceStation &S)
    {
        this->S = &S;
    }
    void seize(Thief &thief);
    int getBonus()
    {
        return bonus;
    }

private:
    int bonus;
    PoliceStation *S;
};

class Thief
{
public:
    Thief(int n) : money(n) {}
    void setMoney(int n = 0)
    {
        money = n;
    }

private:
    int money;
};

class PoliceStation
{
public:
    PoliceStation(int n) : prestige(n)
    {
        policemans = new Police *[10];
    }
    PoliceStation &addPolice(Police &police)
    {
        policemans[index++] = &police;
        police.setPS(*this);
        return *this;
    }
    void addPrestige()
    {
        prestige++;
    }
    void printPrestige()
    {
        cout << prestige << endl;
    }

private:
    Police **policemans;
    int index = 0;
    int prestige;
};

int main()
{
    PoliceStation S(100);
    Police p1;
    Police p2;
    Police p3;
    S.addPolice(p1).addPolice(p2).addPolice(p3);
    Thief t1(500);
    Thief t2(800);
    Thief t3(300);
    Thief t4(1000);
    p1.seize(t2);
    p1.seize(t3);
    p2.seize(t4);
    S.printPrestige();
    cout << p1.getBonus() << endl
         << p2.getBonus() << endl
         << p3.getBonus();
    return 0;
}

void Police::seize(Thief &thief)
{
    bonus += 100;
    S->addPrestige();
    thief.setMoney(0);
}