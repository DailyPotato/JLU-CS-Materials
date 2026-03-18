# include "utils.hpp"
# include <iostream>

using std::cout;

void printSeparator()
{
    cout<<"-----------------------------"<<std::endl;
}

void printStatistics(int addCount,int subCount,int mulCount,int rectCount,int triCount)
{
    cout<<"Function call statistics:"<<std::endl;
    cout<<"add: "<<addCount<<" times"<<std::endl;
    cout<<"subtract: "<<subCount<<" times"<<std::endl;
    cout<<"multiply: "<<mulCount<<" times"<<std::endl;
    cout<<"rectangle: "<<rectCount<<" times"<<std::endl;
    cout<<"triangle: "<<triCount<<" times"<<std::endl;
}