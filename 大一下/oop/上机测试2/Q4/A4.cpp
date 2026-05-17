#include <iostream>
using namespace std;

class Account
{
public:
    Account(){cout<<"constructor with no para"<<endl;}
    Account(const char*,double=0.0){cout<<"constructor with para"<<endl;}
    Account(const Account& init){cout<<"copy constructor"<<endl;}
};

int main()
{
    Account acct;
    Account acct2=acct;
    Account acct3("Anna Engel", 400.0);
    Account acct4=Account(acct3);
    return 0;
}