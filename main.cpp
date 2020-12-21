#include "app.h"


int main(int argc, char *argv[])
{
    App app;
    bool appError = 0;
    if (argc == 3)
    {
        appError = app.run(argv[1], argv[2]);
    } else
    {
        appError = app.run();
    }
    return appError;
}
