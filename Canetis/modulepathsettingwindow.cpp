#include "modulepathsettingwindow.h"
#include "ui_modulepathsettingwindow.h"

ModulePathSettingWindow::ModulePathSettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModulePathSettingWindow)
{
    ui->setupUi(this);
}

ModulePathSettingWindow::~ModulePathSettingWindow()
{
    delete ui;
}
