#pragma once
<<<<<<< HEAD

#include "UI/GUI/guistate.h"
#include <memory>


namespace dupl
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
=======
>>>>>>> 301e9eb3d473f2993fca763422e4693cb196ffe4
