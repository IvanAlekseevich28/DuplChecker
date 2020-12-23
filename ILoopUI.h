#ifndef ILOOPUI_H
#define ILOOPUI_H


#include <QList>
#include <QMainWindow>
#include <core/coreadapter.h>


namespace CONTROLLER
{
class ILoopUI : public QMainWindow
{
public:
    virtual void setAdpter(const std::shared_ptr<CONTROLLER::ICore>& adapter)=0;

    virtual ~ILoopUI(){}

protected:
    ILoopUI(QWidget *parent = nullptr) : QMainWindow(parent) {}
};
}
#endif // ILOOPUI_H
