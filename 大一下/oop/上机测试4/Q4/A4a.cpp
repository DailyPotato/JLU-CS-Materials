#include <iostream>
#include <string>
using namespace std;
class Woman;
class Man
{
public:
    Man(string name, Woman *wife = NULL) : name(name), wife(wife) {}
    void getMarried(Woman &);
    void divorce(Woman &);
    Woman *getWife();
    void setWife(Woman *);
    string getName()
    {
        return name;
    }
private:
    string name;
    Woman *wife;
};

class Woman
{
public:
    Woman(string name, Man *husband = NULL) : name(name), husband(husband) {}
    void getMarried(Man &);
    void divorce(Man &);
    Man *getHusband();
    void setHusband(Man *);
    string getName()
    {
        return name;
    }
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
    cout<<"Married " << name << " and " << w.getName() << endl;
}

void Woman::getMarried(Man &m)
{
    if (husband == NULL && m.getWife() == NULL)
    {
        husband = &m;
        m.setWife(this);
    }
    cout<<"Married " << m.getName() << " and " << name << endl;
}

void Man::divorce(Woman &w)
{
    cout<<"Divorcing " << name << " and " << w.getName() << endl;
    wife = NULL;
    w.setHusband(NULL);
    
}

void Woman::divorce(Man &m)
{
    cout<<"Divorcing " << m.getName() << " and " << name << endl;
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

int main()
{
    Man man("John");
    Woman woman("Jane");
    man.getMarried(woman);
    man.divorce(woman);
    woman.getMarried(man);
    woman.divorce(man);
    return 0;
}