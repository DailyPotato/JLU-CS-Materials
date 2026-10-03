#include<iostream>
#include<string>
using namespace std;

bool func(string& str,string& sub)
{
    int index=0;
    int len=sub.length();
    if(len==0)
    {
        return true;
    }
    if(len>str.length())
    {
        return false;
    }
    for(int i=0;i<str.length()-len+1;i++)
    {
        if(str[i]==sub[0]&&str[i+len-1]==sub[len-1])
        {
            if(len<=2)
            {
                return true;
            }
            string temp=str.substr(i+1,len-2);
            if(temp==sub.substr(1,len-2))
            {
                return true;
            }
        }
    }
    return false;
}