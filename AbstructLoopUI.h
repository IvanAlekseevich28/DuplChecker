#ifndef ABSTRACTLOOPUI_H
#define ABSTRACTLOOPUI_H


#include <QList>
#include <QMainWindow>
#include "ICore.h"
#include "AbstratStateController.h"


namespace CONTROLLER
{
class AbstructLoopUI : public QMainWindow
{
public:
    void setAdpter(const std::shared_ptr<ICore>& adapter)
    {m_coreAdapter = adapter;}

    void setStateController(
            const std::shared_ptr<AbstratStateController>& stateController)
    {m_stateController = stateController;}

    virtual bool load()=0;
    virtual bool save()=0;

    virtual ~AbstructLoopUI(){}

protected:
    AbstructLoopUI(QWidget *parent = nullptr) : QMainWindow(parent) {}

    std::shared_ptr<ICore> m_coreAdapter;
    std::shared_ptr<AbstratStateController> m_stateController;
};
}
#endif // ABSTRACTLOOPUI_H
