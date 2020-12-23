#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../ILoopUI.h"
#include <QStringListModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public CONTROLLER::ILoopUI
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setAdpter(const std::shared_ptr<CONTROLLER::ICore> &adapter)override;

private:
    QString selectDir();
private slots:
    void on_pushButton_go_released();

    void on_pushButton_selectDir1_released();

    void on_pushButton_selectDir2_released();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<CONTROLLER::ICore> m_adapter;
    std::unique_ptr<QStringListModel> m_model;
};
#endif // MAINWINDOW_H
