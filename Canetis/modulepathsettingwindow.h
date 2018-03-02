#ifndef MODULEPATHSETTINGWINDOW_H
#define MODULEPATHSETTINGWINDOW_H

#include <QDialog>

namespace Ui {
class ModulePathSettingWindow;
}

class ModulePathSettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModulePathSettingWindow(QWidget *parent = 0);
    ~ModulePathSettingWindow();

private:
    Ui::ModulePathSettingWindow *ui;
};

#endif // MODULEPATHSETTINGWINDOW_H
