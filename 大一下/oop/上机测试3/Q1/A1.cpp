#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
public:
    MyString(const char *pData = NULL);
    MyString(const MyString &);
    ~MyString();
    MyString &operator=(const MyString &);
    MyString &operator+=(const MyString &);
    operator char *() const;

private:
    char *mpData;
};

const MyString operator+(const MyString &str1, const MyString &str2);
ostream &operator<<(ostream &os, const MyString &str);

MyString::MyString(const char *pData) : mpData(pData ? new char[strlen(pData) + 1] : NULL)
{
    if (pData)
    {
        strcpy(mpData, pData);
    }
}

MyString::MyString(const MyString &str):mpData(nullptr)
{
    if (str.mpData)
    {
        mpData = new char[strlen(str.mpData) + 1];
        strcpy(mpData, str.mpData);
    }
}

MyString::~MyString()
{
    delete [] this->mpData;
    mpData = nullptr;
}

MyString& MyString::operator=(const MyString &str)
{
    if (this != &str)
    {
        delete [] this->mpData;
        mpData = nullptr;
        if (str.mpData)
        {
            mpData = new char[strlen(str.mpData) + 1];
            strcpy(mpData, str.mpData);
        }
    }
    return *this;
}

MyString::operator char *() const
{
    return (mpData ? mpData : const_cast<char *>(""));
}

MyString& MyString::operator+=(const MyString &str)
{
    if (str.mpData)
    {
        size_t oldlen=mpData?strlen(mpData):0;
        char *newData = new char[oldlen + strlen(str.mpData) + 1];
        if(mpData)
        {
            strcpy(newData, mpData);
        }
        else
        {
            newData[0]='\0';
        }
        strcat(newData, str.mpData);
        delete [] mpData;
        mpData = newData;
    }
    return *this;
}

const MyString operator+(const MyString &str1, const MyString &str2)
{
    MyString result(str1);
    result += str2;
    return result;
}

ostream &operator<<(ostream &os, const MyString &str)
{
    os << (char *)str;
    return os;
}

int main()
{
    MyString str1("Hello");
    MyString str2(", ");
    MyString str3("World!");
    MyString str4{};
    str4=str1;
    str4+=str2;
    str4=str4+str3;
    cout << str4 << endl;
    return 0;
}