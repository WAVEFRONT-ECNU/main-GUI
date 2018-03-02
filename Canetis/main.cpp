#include "rwconfig.h"
#include "mainwindow.h"
#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::string configpath = "./config.cfg";
    rwConfig config;
    config.loadConfig(configpath);
    MainWindow w;
    w.show();
    return a.exec();
}
