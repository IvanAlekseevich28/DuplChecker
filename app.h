#ifndef APP_H
#define APP_H


#include <QString>
#include "core/coreadapter.h"


class App
{
public:
    App();

    bool run();
    bool run(char* path1, char* path2);

private:
    std::unique_ptr<CORE::CoreAdapter> m_core;
};

#endif // APP_H
