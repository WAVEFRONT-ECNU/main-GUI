#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modulepathsettingwindow.h"
#include "rwconfig.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    rwConfig mainconfig;

private slots:
    void on_actionSettingModulePath_triggered();

private:
    Ui::MainWindow *ui;
    ModulePathSettingWindow *view;
};

#endif // MAINWINDOW_H
