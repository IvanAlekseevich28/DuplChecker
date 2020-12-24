#ifndef APP_H
#define APP_H


#include <QString>
#include "core/coreadapter.h"
<<<<<<< HEAD
#include "controller/iloopui.h"
=======
#include "controller/baseloopui.h"

>>>>>>> 301e9eb3d473f2993fca763422e4693cb196ffe4

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

#endif // APP_H
