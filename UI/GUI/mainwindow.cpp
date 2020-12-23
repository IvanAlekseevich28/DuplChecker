#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include "UI/textformater.h"


MainWindow::MainWindow(QWidget *parent)
    : CONTROLLER::AbstructLoopUI(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->centralwidget->setLayout(ui->verticalLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_go_released()
{
    save();
    goCore();
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
    return QFileDialog::getExistingDirectory(this,
                                             QString::fromUtf8("Select directory"),
                                             QDir::currentPath(),
                                             QFileDialog::Option::ShowDirsOnly);
}

bool MainWindow::goCore()
{
    QString p1, p2;
    if (ui->lineEdit_path1->text().size() == 0) return false;
    p1 = ui->lineEdit_path1->text();

    if (ui->lineEdit_path2->text().size() == 0)
        p2 = p1;
    else
        p2 = ui->lineEdit_path2->text();

    if (!m_coreAdapter) return false;

    auto rawLst = m_coreAdapter->compareTwoDirs(p1,p2);

    TextFormater tf;
    m_model.reset(new QStringListModel(tf.formatPathsList(rawLst, TextFormater::Pretty)));


    ui->listView->setModel(m_model.get());

    return true;
}

bool MainWindow::load()
{
    if(!m_stateController) return false;

    if(!m_stateController->load()) return false;

    auto state = m_stateController->getGUIState();
    ui->lineEdit_path1->setText(state.path1);
    ui->lineEdit_path2->setText(state.path2);

    return true;
}

bool MainWindow::save()
{
    if(!m_stateController) return false;

    GUIState state;
    state.path1 = ui->lineEdit_path1->text();
    state.path2 = ui->lineEdit_path2->text();
    m_stateController->setGUIState(state);

    if(!m_stateController->save())
        return false;
    else
        return true;
}


