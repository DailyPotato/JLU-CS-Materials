#include "print_this.h"
#include "print_that.h"

int main()
{
#ifdef DO_THIS
    print_this("abc");
#else
    print_that("abc");
#endif
    std::cout << "call count: " << callCount << std::endl;
    return 0;
}