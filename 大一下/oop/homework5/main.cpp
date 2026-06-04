#include "CalculatorApp.h"

int main(int argc, char* argv[])
{
    if (argc > 1) {
        // 动态对象创建演示：命令行模式使用 new/delete 管理对象。
        CalculatorApp* app = new CalculatorApp();
        int exitCode = app->runCommandLine(argc, argv);
        delete app;
        return exitCode;
    }

    // 匿名对象创建演示：创建后立即析构，用于观察生命周期。
    CalculatorApp();

    // 栈对象创建演示：交互模式使用该对象运行程序。
    CalculatorApp app;
    app.runInteractive();
    return 0;
}
