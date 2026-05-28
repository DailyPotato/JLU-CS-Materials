#include <iostream>
using namespace std;

class Thief;
class PoliceStation;
class Walker
{
public:
    Walker(int n):money(n){}
    int getMoney()
    {
        return money;
    }
    void setMoney(int n)
    {
        money=n;
    }
private:
    int money;
};
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
    void steal(Walker &walker)
    {
        money += walker.getMoney();
        walker.setMoney(0);
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
    Walker w(100);
    PoliceStation S(100);
    Police p1;
    Police p2;
    Police p3;
    S.addPolice(p1).addPolice(p2).addPolice(p3);
    Thief t1(500);
    Thief t2(800);
    Thief t3(300);
    Thief t4(1000);

    t1.steal(w);
    cout << "Walker's money: " << w.getMoney() << endl;
    p1.seize(t2);
    p1.seize(t3);
    p2.seize(t4);
    cout<<"S prestige: ";
    S.printPrestige();
    cout << "p1: Bonus: " << p1.getBonus() << endl
         << "p2: Bonus: " << p2.getBonus() << endl
         << "p3: Bonus: " << p3.getBonus() << endl;
    return 0;
}

void Police::seize(Thief &thief)
{
    bonus += 100;
    S->addPrestige();
    thief.setMoney(0);
}