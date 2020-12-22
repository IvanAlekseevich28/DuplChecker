#ifndef APP_H
#define APP_H


#include <QString>
#include "core/coreadapter.h"
#include <QMainWindow>


class App
{
public:
    App();

    bool run(int argc, char *argv[]);
    bool run(char* path0, char* path1, char* path2);

private:
    std::unique_ptr<CORE::CoreAdapter> m_core;
    std::unique_ptr<QMainWindow>    m_gui;
};

#endif // APP_H
