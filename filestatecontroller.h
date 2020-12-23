#ifndef FILESTATECONTROLLER_H
#define FILESTATECONTROLLER_H


#include "AbstratStateController.h"
#include <memory>
#include <QFile>


namespace CONTROLLER
{
class FileStateController : public AbstratStateController
{
public:
    FileStateController();
    ~FileStateController()override;

    GUIState getGUIState()const override;
    void setGUIState(const GUIState& state) override;

    bool save() override;
    bool load() override;

private:


private:
    std::shared_ptr<GUIState> m_guiState;

};
}

#endif // FILESTATECONTROLLER_H
