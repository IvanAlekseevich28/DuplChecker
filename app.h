#pragma once

#include <QString>
#include "controller/icore.h"
#include "controller/iloopui.h"

namespace Dupl
{
class App
{
public:
    App();

    bool run(int argc, char* argv[]);

private:
    bool runGUI(int argc, char* argv[]);
    bool runCLI(int argc, char* argv[]);

private:
    std::shared_ptr<ICore>  m_core;
    std::shared_ptr<ILoopUI>    m_gui;
};
}
