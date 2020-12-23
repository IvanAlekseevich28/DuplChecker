#include "app.h"

#include "UI/CLI/textoutput.h"
#include "UI/GUI/mainwindow.h"
#include <QApplication>
#include "filestatecontroller.h"


App::App() : m_core(new CORE::CoreAdapter())
{

}

bool App::run(int argc, char *argv[])
{
    QApplication app(argc, argv);

    m_gui.reset(new MainWindow);
    m_gui->setAdpter(m_core);

    if (argc > 0)
    {
        std::shared_ptr<CONTROLLER::AbstratStateController>
                pStController(new CONTROLLER::FileStateController);
        pStController->setPath(QString(argv[0]) + "_gui_save.txt");
        m_gui->setStateController(pStController);
        m_gui->load();
    }

    m_gui->show();

    return app.exec();
}

bool App::run(char *path0, char* path1, char* path2)
{
    if (!m_core) return false;
    CLI::TextOutput output;

    return !output.print(m_core->compareTwoDirs(QString(path1), QString(path2)));
}
