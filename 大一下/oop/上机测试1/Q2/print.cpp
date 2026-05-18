#include "print.h"

int callCount =0;

void print(const std::string& s)
{
    std::cout<<s<<std::endl;
    callCount++;
}