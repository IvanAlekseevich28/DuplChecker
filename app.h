#ifndef APP_H
#define APP_H


#include <QString>
#include "core/coreadapter.h"
#include "controller/baseloopui.h"

namespace dupl
{
class App
{
public:
    App();

    bool run(int argc, char *argv[]);
    bool run(char* path0, char* path1, char* path2);

private:
    std::shared_ptr<CoreAdapter>  m_core;
    std::unique_ptr<AbstructLoopUI>    m_gui;
};
}

#endif // APP_H
