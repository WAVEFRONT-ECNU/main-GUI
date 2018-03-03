#ifndef MODULEPATHSETTINGWINDOW_H
#define MODULEPATHSETTINGWINDOW_H

#include <QDialog>
#include <QWidget>
#include <string>
#include "rwconfig.h"

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

namespace Ui {
class ModulePathSettingWindow;
}

class ModulePathSettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModulePathSettingWindow(QWidget *parent = 0);
    ~ModulePathSettingWindow();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ModulePathSettingWindow *ui;
};

#endif // MODULEPATHSETTINGWINDOW_H
