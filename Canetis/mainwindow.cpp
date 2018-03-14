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
    wchar_t* argv[0];
    PySys_SetArgv(0, argv);
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
    // LOAD CONFIG AND ADD MODULE NAME
    std::string configSlicer[2], configClustering[2], configRecognition[2];
    rwConfig config;
    configSlicer[0] = config.getConfig("SlicerPath");
    configSlicer[1] = "WaveSlicer";
    configClustering[0] = config.getConfig("ClusteringPath");
    configClustering[1] = "Clustering";
    configRecognition[0] = config.getConfig("RecognitionPath");
    if(configClustering[0] == "" or configRecognition[0] == "" or configSlicer[0] == "")
    {
        printLogsOnScreen("Please set the path of modules first.");
        on_actionSettingModulePath_triggered();
        return;
    }
    // ADD PYTHON MODULE PATH TO SYS.PATH
    // IMPORT MODULES AND WHEN ERROR THROW IT
    std::string pythonConfigs[2][2] = {{configClustering[0],configClustering[1]}, {configSlicer[0],configSlicer[1]}};
    for (int i = 0; i < 2; i++) {
        std::string chdir_cmd = std::string("sys.path.append(\'" + pythonConfigs[i][0] + "\')");
        PyRun_SimpleString(chdir_cmd.c_str());
        PyObject* pModule = PyImport_ImportModule(pythonConfigs[i][1].c_str());
        if (pModule == NULL or PyErr_Occurred()) // IF LOAD MODULE ERR
            {
                std::cerr << "[ERROR] Python import module "<<pythonConfigs[i][1]<<" failed." << std::endl;
                PyErr_Print();
                return;
            }
            std::cout << "[INFO] Python get module "<<pythonConfigs[i][1]<<" succeed." << std::endl;

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
