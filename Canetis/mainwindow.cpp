#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

bool workMode; // 0 is file; 1 is stream.
std::string audioFilePath;

MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \brief Show log on both terminal and ui
/// \param log
///
void MainWindow::printLogsOnScreen(std::string log)
{
    std::cout<<"Log: "<<log<<std::endl;
    ui->labelLog->setText(QString::fromStdString(log));
}

///
/// \brief Open The Setting Window.
///
void MainWindow::on_actionSettingModulePath_triggered()
{
    view = new ModulePathSettingWindow(this);
    view->show();
}

///
/// \brief Open an Audio File.
///
void MainWindow::on_actionFile_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(NULL,"Choose Audio File",".","PCM Audio(*.wav)");
    if(file_name == "")
        return;
    workMode = false;
    audioFilePath = file_name.toStdString();
    printLogsOnScreen("Set file: "+audioFilePath);
}

///
/// \brief Open Stream.
///
void MainWindow::on_actionStream_triggered()
{
    workMode = true;
    printLogsOnScreen("Set mode stream");
}
