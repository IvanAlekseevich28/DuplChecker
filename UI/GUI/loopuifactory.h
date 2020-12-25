#pragma once

#include "../../controller/iloopui.h"
#include <memory>


namespace dupl
{

class LoopUIFactory
{
public:
    LoopUIFactory();

    enum eLoopUI
    {
        SimpleGUI
    };

    static std::shared_ptr<ILoopUI> getLoopUI(eLoopUI eType = SimpleGUI);
};
}
