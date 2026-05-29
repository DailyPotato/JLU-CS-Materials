#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    Person(int age, string name, bool gender) : age(age), name(name), gender(gender) {}
    string getName()
    {
        return name;
    }

private:
    int age;
    string name;
    bool gender;
};

class Employee : public Person
{
public:
    Employee(int num, int age, string name, bool gender) : number(num), Person(age, name, gender) {}
    void show()
    {
        cout << "name:" << getName() << " is an Employee." << endl;
    }

private:
    int number;
};

class Executive : public Employee
{
public:
    Executive(int num, int age, string name, bool gender) : Employee(num, age, name, gender) {}
    void show()
    {
        cout << "name:" << getName() << " is an Executive." << endl;
    }

private:
};

int main()
{
    Employee **emps = new Employee *[5];
    for (int i = 0; i < 5; ++i)
    {
        emps[i] = new Employee(i + 1, 25 + i, "Employee" + to_string(i + 1), i % 2 == 0);
    }
    Executive **execs = new Executive *[5];
    for (int i = 0; i < 5; ++i)
    {
        execs[i] = new Executive(i + 1, 30 + i, "Executive" + to_string(i + 1), i % 2 == 0);
    }
    for (int i = 0; i < 5; ++i)
    {
        emps[i]->show();
    }
    for (int i = 0; i < 5; ++i)
    {
        execs[i]->show();
    }
    execs[0]->Employee::show();
    return 0;
}