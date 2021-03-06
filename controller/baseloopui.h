#pragma once

#include <QList>
#include <QMainWindow>
#include "icore.h"
#include "iloopui.h"

namespace Dupl
{
class BaseLoopUI : public QMainWindow, public ILoopUI
{
public:
    void setCore(const std::shared_ptr<ICore>& core) override
        {m_core = core;}

    void setStateController(
            const std::shared_ptr<IStateController>& stateController) override
        {m_stateController = stateController;}

    void show() override {QMainWindow::show();}

    virtual bool load() override=0;
    virtual bool save() override=0;

    virtual ~BaseLoopUI(){}

protected:
    BaseLoopUI(QWidget *parent = nullptr) : QMainWindow(parent) {}

    std::shared_ptr<ICore> m_core;
    std::shared_ptr<IStateController> m_stateController;
};
}
