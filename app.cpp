#include "app.h"

#include "UI/CLI/textoutput.h"


App::App() : m_core(new CORE::CoreAdapter())
{

}

bool App::run()
{

    return false;
}

bool App::run(char* path1, char* path2)
{
    if (!m_core) return false;
    CLI::TextOutput output;

    return output.print(m_core->compareTwoDirs(QString(path1), QString(path2)));
}
