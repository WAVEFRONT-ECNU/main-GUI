#include "modulepathsettingwindow.h"
#include "ui_modulepathsettingwindow.h"

ModulePathSettingWindow::ModulePathSettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModulePathSettingWindow)
{
    ui->setupUi(this);
    // TODO add config load
    std::string configSlicer, configClustering, configRecognition;
    rwConfig config;
    configSlicer = config.getConfig("SlicerPath");
    configClustering = config.getConfig("ClusteringPath");
    configRecognition = config.getConfig("RecognitionPath");
    txtSlicer->setText(QString::fromStdString(configSlicer));
    txtClustering->setText(QString::fromStdString(configClustering));
    txtRecognition->setText(QString::fromStdString(configRecognition));
}

ModulePathSettingWindow::~ModulePathSettingWindow()
{
    delete ui;
}

void ModulePathSettingWindow::on_buttonBox_accepted()
{
    // TODO add config saving
}

void ModulePathSettingWindow::on_buttonBox_rejected()
{

}
