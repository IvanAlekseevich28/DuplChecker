#pragma once

#include "UI/GUI/guistate.h"
#include <memory>

namespace Dupl
{
class IStateController
{
public:
    virtual GUIState getGUIState()const=0;

    virtual void setGUIState(const GUIState& state)=0;

    virtual bool save()=0;
    virtual bool load()=0;

    virtual void setPath(const QString& path)=0;

    virtual ~IStateController(){}

protected:
    IStateController() {}
};
}
