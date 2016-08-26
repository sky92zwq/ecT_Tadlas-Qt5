#-------------------------------------------------
#
# Project created by QtCreator 2016-08-18T11:22:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cs_ftfunction.cpp

HEADERS  += mainwindow.h \
    cs_ftfunction.h \
    ftd2xx.h

FORMS    += mainwindow.ui



LIBS += ftd2xx.dll


