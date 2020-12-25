#pragma once

#include "icore.h"
#include "istatecontroller.h"

namespace Dupl
{
class ILoopUI
{
public:
    virtual void setCore(const std::shared_ptr<ICore>& core)=0;

    virtual void setStateController(
            const std::shared_ptr<IStateController>& stateController)=0;

    virtual void show()=0;

    virtual bool load()=0;
    virtual bool save()=0;

    virtual ~ILoopUI(){}

protected:
    ILoopUI(){}

};
}
