#include "modulepathsettingwindow.h"
#include "ui_modulepathsettingwindow.h"

ModulePathSettingWindow::ModulePathSettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModulePathSettingWindow)
{
    ui->setupUi(this);
    // TODO add config load
    std::string configSlicer, configClustering, configRecognition = "";
    rwConfig config;
    configSlicer = config.getConfig("SlicerPath");
    configClustering = config.getConfig("ClusteringPath");
    configRecognition = config.getConfig("RecognitionPath");
    ui->txtSlicer->setText(QString::fromStdString(configSlicer));
    ui->txtClustering->setText(QString::fromStdString(configClustering));
    ui->txtRecognition->setText(QString::fromStdString(configRecognition));
}

ModulePathSettingWindow::~ModulePathSettingWindow()
{
    delete ui;
}

///
/// \brief Save the path config.
///
void ModulePathSettingWindow::on_buttonBox_accepted()
{
    // TODO add config saving
    rwConfig config;
    config.setConfig("SlicerPath",ui->txtSlicer->text().toStdString());
    config.setConfig("ClusteringPath",ui->txtClustering->text().toStdString());
    config.setConfig("RecognitionPath",ui->txtRecognition->text().toStdString());
}

void ModulePathSettingWindow::on_buttonBox_rejected()
{
    // NO CANCEL ACTION
}

///
/// \brief Button SetSlicer Clicked.
///
void ModulePathSettingWindow::on_btnSetSlicer_clicked()
{
    QString folder = chooseFolder();
    if(folder != "")
    {
        ui->txtSlicer->setText(folder);
    }
}

///
/// \brief Button SetClustering Clicked.
///
void ModulePathSettingWindow::on_btnSetClustering_clicked()
{
    QString folder = chooseFolder();
    if(folder != "")
    {
    ui->txtClustering->setText(folder);
    }
}

///
/// \brief Button SetRecognition Clicked.
///
void ModulePathSettingWindow::on_btnSetRecognition_clicked()
{
    QString folder = chooseFolder();
    if(folder != "")
    {
    ui->txtRecognition->setText(folder);
    }
}

///
/// \brief Choose the folder and get its path
/// \return path of choosen folder
///
QString ModulePathSettingWindow::chooseFolder()
{
    QString file_name = QFileDialog::getExistingDirectory(NULL,"Choose Folder",".");
    return file_name;
}

