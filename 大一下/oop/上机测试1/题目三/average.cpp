#include <iostream>
#include <string>

double average(int count, char * numbers[])
{
    double sum = 0.0;
    for(int i=0;i<count;i++)
    {
        sum += std::stod(numbers[i]);
    }
    return sum / count;
}

int main(int argc, char *argv[])
{
    double ans=average(argc - 1, argv + 1);
    std::cout<<"average: "<<ans<<std::endl;
    return 0;
}