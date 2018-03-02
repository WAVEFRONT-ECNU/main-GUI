#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// OPEN MODULE PATH SETTING WINDOW
void MainWindow::on_actionSettingModulePath_triggered()
{
    view = new ModulePathSettingWindow(this);
    view->show();
}
