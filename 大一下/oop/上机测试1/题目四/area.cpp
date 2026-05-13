#include <iostream>
#include <cmath>
double area(double a=3,double b=4,double c=5)
{
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
    std::cout<<"Area: "<<area()<<std::endl;
    std::cout<<"Area: "<<area(3)<<std::endl;
    std::cout<<"Area: "<<area(3,4)<<std::endl;
    std::cout<<"Area: "<<area(3,4,5)<<std::endl;
    return 0;
}