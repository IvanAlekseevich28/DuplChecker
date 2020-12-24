#pragma once

#include <QString>
#include "core/coreadapter.h"
#include "controller/iloopui.h"


namespace dupl
{
class App
{
public:
    App();

    bool run(int argc, char *argv[]);

private:
    bool runGUI(int argc, char *argv[]);
    bool runCLI(int argc, char *argv[]);
    QString supplementPath(const QString &firstPath,
                           const QString& shortPath)const;

private:
    std::shared_ptr<CoreAdapter>  m_core;
    std::unique_ptr<ILoopUI>    m_gui;
};
}
