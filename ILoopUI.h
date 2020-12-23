#ifndef ILOOPUI_H
#define ILOOPUI_H


#include <QList>
#include <QMainWindow>
#include "ICore.h"
#include "AbstratStateController.h"


namespace CONTROLLER
{
class ILoopUI : public QMainWindow
{
public:
    virtual void setAdpter(const std::shared_ptr<ICore>& adapter)=0;
    virtual void setStateController(
            const std::shared_ptr<AbstratStateController>& controller)=0;

    virtual ~ILoopUI(){}

protected:
    ILoopUI(QWidget *parent = nullptr) : QMainWindow(parent) {}
};
}
#endif // ILOOPUI_H
