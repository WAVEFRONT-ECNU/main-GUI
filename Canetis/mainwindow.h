#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modulepathsettingwindow.h"
#include "rwconfig.h"
#include "Python.h"
#include "jni.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSettingModulePath_triggered();

    void on_actionFile_triggered();

    void on_actionStream_triggered();

    void on_btnStartStop_clicked();

private:
    Ui::MainWindow *ui;
    ModulePathSettingWindow *view;
    void printLogsOnScreen(std::string);
    bool workMode;
    bool startStatus;
    std::string audioFilePath;
};

#endif // MAINWINDOW_H
