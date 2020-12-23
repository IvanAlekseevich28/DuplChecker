#ifndef ABSTRACTSTATECONTROLLER_H
#define ABSTRACTSTATECONTROLLER_H


#include "UI/GUI/guistate.h"
#include <memory>


namespace CONTROLLER
{
class AbstratStateController
{
public:
    GUIState getGUIState()const
    {return !m_guiState ? GUIState() : *m_guiState;}

    void setGUIState(const GUIState& state)
    {m_guiState.reset(new GUIState(state));}

    virtual bool save()=0;
    virtual bool load()=0;

    virtual void setPath(const QString& path) {m_path =path;}

    virtual ~AbstratStateController(){}

protected:
    AbstratStateController() {}
    QString getPath()const {return  m_path;};

private:
    QString m_path;
    std::shared_ptr<GUIState> m_guiState;
};
}
#endif // ABSTRACTSTATECONTROLLER_H
