# include "utils.hpp"
# include "constants.hpp"
# include <iostream>
# include "arithmetic.hpp"
# include "geometry.hpp"
using std::cout;

const std::string countStrArr[] = {"add", "subtract", "multiply", "divide", "rectangle", "triangle"};

void printSeparator(int length, char ch)
{
    for(int i=0;i<length;i++)
        cout<<ch;
    cout<<std::endl;
}

void printSeparator(char ch)
{
    printSeparator(MAX_PRINT_LENGTH, ch);
}

void printStatistics(const int& addCount, const int& subCount, const int& mulCount, const int& divCount, const int& rectCount, const int& triCount)
{
    const int countArr[] = {addCount, subCount, mulCount, divCount, rectCount, triCount};
    for(auto i=0;i<sizeof(countArr)/sizeof(int);i++)
    {
        cout<<countStrArr[i]<<": "<<countArr[i]<<" times"<<std::endl;
    }
    return;
}
