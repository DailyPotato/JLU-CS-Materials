#include "Calculator.h"
#include <string>


int main(int argc, char *argv[])
{
    Calculator().printHelp();
    Calculator::printVersion();
    Calculator cal;
    if (argc == 1)
    {
        cal.runInteractive();
    }
    else if (argc >= 3)
    {

    }
    else
    {
        
    }
    return 0;
}