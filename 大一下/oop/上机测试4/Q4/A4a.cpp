#include <iostream>
#include <string>
using namespace std;
class Woman;
class Man
{
public:
    Man(Woman *wife = NULL) : wife(wife) {}
    void getMarried(Woman &);
    void divorce(Woman &);
    Woman *getWife();
    void setWife(Woman *);

private:
    string name;
    Woman *wife;
};

class Woman
{
public:
    Woman(Man *husband = NULL) : husband(husband) {}
    void getMarried(Man &);
    void divorce(Man &);
    Man *getHusband();
    void setHusband(Man *);

private:
    string name;
    Man *husband;
};

void Man::getMarried(Woman &w)
{
    if (wife == NULL && w.getHusband() == NULL)
    {
        wife = &w;
        w.setHusband(this);
    }
}

void Woman::getMarried(Man &m)
{
    if (husband == NULL && m.getWife() == NULL)
    {
        husband = &m;
        m.setWife(this);
    }
}

void Man::divorce(Woman &w)
{
    wife = NULL;
    w.setHusband(NULL);
}

void Woman::divorce(Man &m)
{
    husband = NULL;
    m.setWife(NULL);
}

Woman *Man::getWife()
{
    return wife;
}

Man *Woman::getHusband()
{
    return husband;
}

void Man::setWife(Woman *w)
{
    wife = w;
}

void Woman::setHusband(Man *m)
{
    husband = m;
}