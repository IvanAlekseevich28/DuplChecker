#include "app.h"

#include "UI/CLI/textoutput.h"
#include "UI/GUI/mainwindow.h"
#include <QApplication>


App::App() : m_core(new CORE::CoreAdapter())
{

}

bool App::run(int argc, char *argv[])
{
    QApplication app(argc, argv);
    m_gui.reset(new MainWindow);

    m_gui->show();

    return app.exec();
}

bool App::run(char *path0, char* path1, char* path2)
{
    if (!m_core) return false;
    CLI::TextOutput output;

    return !output.print(m_core->compareTwoDirs(QString(path1), QString(path2)));
}
