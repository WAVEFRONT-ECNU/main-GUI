#-------------------------------------------------
#
# Project created by QtCreator 2018-02-28T23:32:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Canetis
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -L/usr/local/lib/ -lconfig++
LIBS += -L/usr/lib/python3.5/config-3.5m-x86_64-linux-gnu -L/usr/lib -lpython3.5m -lpthread -ldl  -lutil -lm  -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions
#INCLUDEPATH += /usr/include/python3.5m /usr/include/python3.5m -Wno-unused-result -Wsign-compare -g -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes
INCLUDEPATH += /usr/include/python3.5m /usr/include/python3.5m -Wno-unused-result -Wsign-compare -g -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes

#JAVA_HOME = ${JAVA_HOME}
JAVA_HOME = /usr/lib/jvm/java-8-oracle
INCLUDEPATH += $$JAVA_HOME/include
INCLUDEPATH += $$JAVA_HOME/include/linux
LIBS += $$JAVA_HOME/jre/lib/amd64/server/libjvm.so

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    modulepathsettingwindow.cpp \
    rwconfig.cpp

HEADERS += \
        mainwindow.h \
    modulepathsettingwindow.h \
    rwconfig.h

FORMS += \
        mainwindow.ui \
    modulepathsettingwindow.ui

QMAKE_CXXFLAGS +=  -Wno-unused-parameter
