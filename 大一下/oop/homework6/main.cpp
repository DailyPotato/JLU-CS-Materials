#include "CalculatorApp.h"

int main(int argc, char* argv[])
{
    if (argc > 1) {
        CalculatorApp* app = new CalculatorApp();
        int exitCode = app->runCommandLine(argc, argv);
        delete app;
        return exitCode;
    }

    CalculatorApp app;
    app.runInteractive();
    return 0;
}
