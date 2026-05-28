#include <iostream>
#include <string>
using namespace std;
class MarriageRecord;
class Woman;
class Man
{
public:
    Man(string n) : name(n), marriageRecord(NULL) {}
    void setMarriage(MarriageRecord *r)
    {
        marriageRecord = r;
    }
    void Marry(Woman &);
    bool getMarriage()
    {
        if (marriageRecord != NULL)
            return true;
        return false;
    }
    string getName()
    {
        return name;
    }
    void getWifeName();
    void divorce();

private:
    string name;
    MarriageRecord *marriageRecord;
};

class Woman
{
public:
    Woman(string n) : name(n), marriageRecord(NULL) {}
    void setMarriage(MarriageRecord *r)
    {
        marriageRecord = r;
    }
    void Marry(Man &);
    bool getMarriage()
    {
        if (marriageRecord != NULL)
            return true;
        return false;
    }
    string getName()
    {
        return name;
    }
    void getHusbandName();
    void divorce();

private:
    string name;
    MarriageRecord *marriageRecord;
};

class MarriageRecord
{
public:
    MarriageRecord(Man *h, Woman *w) : Husband(h), Wife(w)
    {
        h->setMarriage(this);
        w->setMarriage(this);
        cout << "Husband " << h->getName() << " and Wife " << w->getName() << " are married." << endl;
    }
    ~MarriageRecord()
    {
        Husband->setMarriage(NULL);
        Wife->setMarriage(NULL);
        cout << "Husband " << Husband->getName() << " and Wife " << Wife->getName() << " are divorced." << endl;
    }
    Man *getHusband()
    {
        return Husband;
    }
    Woman *getWife()
    {
        return Wife;
    }

private:
    Man *Husband;
    Woman *Wife;
};

void Man::Marry(Woman &w)
{
    if (this->marriageRecord != NULL || w.getMarriage())
    {
        return;
    }
    new MarriageRecord(this, &w);
}

void Woman::Marry(Man &m)
{
    if (this->marriageRecord != NULL || m.getMarriage())
    {
        return;
    }
    new MarriageRecord(&m, this);
}

void Man::getWifeName()
{
    if (marriageRecord != NULL)
    {
        cout << "Wife: " << marriageRecord->getWife()->getName() << endl;
    }
    else
    {
        cout << "No wife." << endl;
    }
}

void Woman::getHusbandName()
{
    if (marriageRecord != NULL)
    {
        cout << "Husband: " << marriageRecord->getHusband()->getName() << endl;
    }
    else
    {
        cout << "No husband." << endl;
    }
}

void Man::divorce()
{
    if (marriageRecord != NULL)
    {
        cout << "Divorcing " << name << " and " << marriageRecord->getWife()->getName() << endl;
        delete marriageRecord;
        marriageRecord = NULL;
    }
}

void Woman::divorce()
{
    if (marriageRecord != NULL)
    {
        cout << "Divorcing " << name << " and " << marriageRecord->getHusband()->getName() << endl;
        delete marriageRecord;
        marriageRecord = NULL;
    }
}

int main()
{
    Man man("John");
    Woman woman("Jane");
    man.Marry(woman);
    man.getWifeName();
    man.divorce();
    woman.Marry(man);
    woman.getHusbandName();
    woman.divorce();
    return 0;
}