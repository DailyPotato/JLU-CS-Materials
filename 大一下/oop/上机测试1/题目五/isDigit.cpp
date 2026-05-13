#include <iostream>

inline bool isDigit(char c)
{
    return c>='0' && c<='9';
}

int main()
{
    char c;
    std::cin>>c;
    if(isDigit(c))
    {
        std::cout<<c<<" is a digit.";
    }
    else
    {
        std::cout<<c<<" is not a digit.";
    }
    return 0;
}