#pragma once

#include "../../controller/baseloopui.h"
#include <QStringListModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace dupl
{
class MainWindow : public BaseLoopUI
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString selectDir();
    bool goCore();

    bool load()override;
    bool save()override;

private slots:
    void on_pushButton_go_released();

    void on_pushButton_selectDir1_released();

    void on_pushButton_selectDir2_released();

private:
    std::unique_ptr<Ui::MainWindow> m_ui;
    std::unique_ptr<QStringListModel> m_model;
};
}

