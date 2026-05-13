#include <iostream>
#include <string>
using namespace std;

class Pen
{
public:
    Pen(const string& c):color(c){}
    virtual void write(const string& s)
    {
        cout<<"write with "<<color<<" pen: "<<s<<endl;
    }
    virtual ~Pen(){}
private:
    string color;

};

class inkPen:public Pen
{
public:
    inkPen(const string& c):Pen(c){}
    virtual void write(const string& s)
    {
        cout<<"write with ink pen: "<<s<<endl;
    }
    virtual ~inkPen(){}
};

class File
{
public:
    File(const string& n):name(n){}
    virtual void open()
    {
        cout<<"open file: "<<name<<endl;
    }
    virtual ~File(){}
private:
    string name;
};

class directory:public File
{
public:
    directory(const string& n):File(n){}
    virtual void open()
    {
        cout<<"open directory: "<<endl;
    }
    virtual ~directory(){}
};

class printer
{
public:
    printer(int level):intLevel(level){}
    int getIntlevel()
    {
        return intLevel;
    }
    void addIntLevel(int n)
    {
        intLevel+=n;
    }
    virtual void print(const string& s)
    {
        cout<<"print: "<<s<<endl;
    }
    virtual ~printer(){}
private:
    int intLevel;
};

class display:public printer
{
public:
    virtual void print(const string& s)
    {
        cout<<"display: "<<s<<endl;
    }
    virtual ~display(){}
};

class planet
{
public:
    planet(long long m,long long v):mass(m),volume(v){}
private:
    long long mass;
    long long volume;
};

class sun:public planet
{
public:
    sun(long long m,long long v):planet(m,v){}
    void shine()
    {
        cout<<"sun shine"<<endl;
    }
};

class moon:public planet
{
public:
    moon(long long m,long long v):planet(m,v){}
    void shine()
    {
        cout<<"moon shine"<<endl;
    }
};