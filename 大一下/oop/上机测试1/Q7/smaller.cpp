#include <iostream>

long& smaller(long& a,long& b)
{
    return a<b?a:b;
}

long& bigger(long& a,long& b)
{
    return a>b?a:b;
}

int main()
{
    int n;
    std::cin>>n;
    long a=1,b=1;
    std::cout<<1<<" ";
    for(int i=0;i<n;i++)
    {
        std::cout<<bigger(a,b)<<" ";
        smaller(a,b)=a+b;
    }
    return 0;
}