#ifndef APP_H
#define APP_H


#include <QString>


class App
{
public:
    App();

    bool run();
    bool run(char* path1, char* path2);
};

#endif // APP_H
