#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Py_Initialize();
    PyRun_SimpleString("import sys");
    std::string chdir_cmd = std::string("sys.path.append(\'/media/qcmiao/Document/computer-competition/canetis-env/lib/python3.5/site-packages\')");
    PyRun_SimpleString(chdir_cmd.c_str());
    workMode = true; startStatus = false;
    audioFilePath = "";
}

bool workMode; // 0 is file; 1 is stream.
bool startStatus; // 0 is not_start; 1 is running
std::string audioFilePath;

MainWindow::~MainWindow()
{
    Py_Finalize();
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
    startStatus = false;
    printLogsOnScreen("Set mode stream");
}

///
/// \brief Start record and reco.
///
void MainWindow::on_btnStartStop_clicked()
{
    // LOAD CONFIG
    std::string configSlicer, configClustering, configRecognition = "";
    rwConfig config;
    configSlicer = config.getConfig("SlicerPath");
    configClustering = config.getConfig("ClusteringPath");
    configRecognition = config.getConfig("RecognitionPath");
    if(configClustering == "" or configRecognition == "" or configSlicer == "")
    {
        printLogsOnScreen("Please set the path of modules first.");
        on_actionSettingModulePath_triggered();
        return;
    }
    std::string configs[3] = {configClustering, configRecognition, configSlicer};
    foreach (std::string path, configs) {
        std::string chdir_cmd = std::string("sys.path.append(\'" + path + "\')");
        PyRun_SimpleString(chdir_cmd.c_str());
    }

    // TODO OPEN FILE OR STREAM
    if(workMode) // when stream
    {
        if(!startStatus)
        {
            // TODO LINK RECORD
            startStatus = true;
            ui->btnStartStop->setText("Stop");
        }
        else {
            // TODO GET AUDIOLIST
            startStatus = false;
            ui->btnStartStop->setText("Start");
        }
    }
    else { // when file
        // TODO SEND AND GET AUDIOLIST
    }

    // TODO SEND TO CLUSTERING

    // TODO SEND TO RECO

    // PRINT IN TABLE
}
