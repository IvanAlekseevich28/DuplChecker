#pragma once

#include "istatecontroller.h"
#include <memory>

namespace Dupl
{
class BaseStateController : public IStateController
{
public:
    virtual bool save() override=0;
    virtual bool load() override=0;

    virtual ~BaseStateController() override{}

    void setPath(const QString& path) override
        {m_path =path;}

    GUIState getGUIState() const override
        {return !m_guiState ? GUIState() : *m_guiState;}

    void setGUIState(const GUIState& state) override
        {m_guiState.reset(new GUIState(state));}

protected:
    BaseStateController() {}
    QString getPath() const
        {return  m_path;};

private:
    QString m_path;
    std::shared_ptr<GUIState> m_guiState;
};
}
