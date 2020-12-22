#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include "UI/textformater.h"


MainWindow::MainWindow(QWidget *parent)
    : CONTROLLER::ILoopUI(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAdpter(const std::shared_ptr<CORE::CoreAdapter> &adapter)
{
    m_adapter = adapter;
}


void MainWindow::on_pushButton_go_released()
{
    QString p1, p2;
    if (ui->lineEdit_path1->text().size() == 0) return;
    p1 = ui->lineEdit_path1->text();

    if (ui->lineEdit_path2->text().size() == 0)
        p2 = p1;
    else
        p2 = ui->lineEdit_path2->text();

    if (!m_adapter) return;

    auto rawLst = m_adapter->compareTwoDirs(p1,p2);

    TextFormater tf;
    m_model.reset(new QStringListModel(tf.formatPathsList(rawLst, TextFormater::NoFullPath)));


    ui->listView->setModel(m_model.get());

}

void MainWindow::on_pushButton_selectDir1_released()
{
    ui->lineEdit_path1->setText(selectDir());
}

void MainWindow::on_pushButton_selectDir2_released()
{
    ui->lineEdit_path2->setText(selectDir());
}

QString MainWindow::selectDir()
{
    return QFileDialog::getOpenFileName(this, "Open directory or file");
}


