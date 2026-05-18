#include "print_this.h"
#include "print_that.h"

int main()
{
    print_this("this is print_this.");
    print_that("this is print_that.");
    std::cout<<"call count: "<<callCount<<std::endl;
    return 0;
}