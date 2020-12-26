#include "app.h"

#include "UI/CLI/textoutput.h"
#include "UI/GUI/loopuifactory.h"
#include <QApplication>
#include "controller/statecontrollerfactory.h"
#include "core/coreadapter.h"
#include <QApplication>
#include <QStringList>

using namespace Dupl;

App::App() : m_core(new CoreAdapter())
{

}

bool App::run(int argc, char *argv[])
{    
    if (argc == 1)
        return runGUI(argc, argv);
    else
        return runCLI(argc, argv);
}

bool App::runGUI(int argc, char *argv[])
{
    const QString startPath = argv[0];
    QApplication app(argc, argv);

    m_gui = LoopUIFactory::getLoopUI();
    m_gui->setCore(m_core);

    if (!startPath.isEmpty())
    {
        std::shared_ptr<IStateController>
                pStController(StateControllerFactory::getStateController());
        pStController->setPath(QString(startPath) + "_gui_save.txt");
        m_gui->setStateController(pStController);
        m_gui->load();
    }

    m_gui->show();
    app.exec();

    return true;
}

bool App::runCLI(int argc, char *argv[])
{
    if (!m_core or argc < 2) return false;
    TextOutput output;
    QString p1 = argv[1];
    QString p2 = argc == 2 ? argv[1] : argv[2];

    return !output.print(m_core->compareTwoDirs(p1, p2));
}
