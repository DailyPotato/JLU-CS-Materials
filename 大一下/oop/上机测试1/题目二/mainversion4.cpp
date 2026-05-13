#include "print_this.h"
#include "print_that.h"
#ifdef DO_THIS
    #define PRINT(x) print_this(#x)
#else
    #define PRINT(x) print_that(#x)
#endif
int main()
{
    PRINT(abc);
    std::cout<<"call count: "<<callCount<<std::endl;
    return 0;
}