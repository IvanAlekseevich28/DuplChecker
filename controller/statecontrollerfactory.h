#pragma once

#include "istatecontroller.h"

namespace Dupl
{
class StateControllerFactory
{
public:
    StateControllerFactory();

    enum eStateController
    {
        SimpleFile
    };

    static std::shared_ptr<IStateController> getStateController(eStateController eType = SimpleFile);
};
}
