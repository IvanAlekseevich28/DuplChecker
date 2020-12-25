#include "loopuifactory.h"

#include "mainwindow.h"


using namespace Dupl;

LoopUIFactory::LoopUIFactory()
{

}

std::shared_ptr<ILoopUI> LoopUIFactory::getLoopUI(eLoopUI eType)
{
    switch (eType)
    {
    case SimpleGUI: return std::shared_ptr<ILoopUI>(new MainWindow);
    }

    return std::shared_ptr<ILoopUI>();
}
