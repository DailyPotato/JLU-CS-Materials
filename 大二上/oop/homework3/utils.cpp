# include "utils.hpp"
# include "constants.hpp"
# include <iostream>
# include "arithmetic.hpp"
# include "geometry.hpp"
using std::cout;
auto countArr = {getAddCountReadOnly(), getSubCountReadOnly(), getMulCountReadOnly(), getDivCountReadOnly(), getRectCountReadOnly(), getTriCountReadOnly()};
const std::string countStrArr[] = {"add", "subtract", "multiply", "divide", "rectangle", "triangle"};

void printSeparator(int length, char ch='-')
{
    for(int i=0;i<length;i++)
        cout<<ch;
    cout<<std::endl;
}

void printSeparator(char ch='-')
{
    printSeparator(MAX_PRINT_LENGTH, ch);
}

void printStatistics(const int& addCount, const int& subCount, const int& mulCount, const int& divCount, const int& rectCount, const int& triCount)
{
    for(auto arr:countArr)
    {
        int index = &arr - &getAddCountReadOnly();
        cout<<countStrArr[index]<<" : "<<arr<<" times"<<std::endl;
    }
}
