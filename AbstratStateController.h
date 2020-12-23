#ifndef ABSTRACTSTATECONTROLLER_H
#define ABSTRACTSTATECONTROLLER_H


#include "UI/GUI/guistate.h"


namespace CONTROLLER
{
class AbstratStateController
{
public:
    virtual GUIState getGUIState()const=0;
    virtual void setGUIState(const GUIState& state)=0;

    virtual bool save()=0;
    virtual bool load()=0;

    virtual void setPath(const QString& path) {m_path =path;}

    virtual ~AbstratStateController(){}

protected:
    AbstratStateController() {}
    QString getPath()const {return  m_path;};

private:
    QString m_path;
};
}
#endif // ABSTRACTSTATECONTROLLER_H
