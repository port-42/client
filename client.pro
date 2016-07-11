#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T18:36:12
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 5):

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectwidget.cpp \
    requests.cpp \
    apicommunicator.cpp \
    summarywidget.cpp

HEADERS  += mainwindow.h \
    connectwidget.h \
    requests.h \
    apicommunicator.h \
    summarywidget.h

FORMS    += mainwindow.ui
