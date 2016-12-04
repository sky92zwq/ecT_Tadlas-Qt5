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
    cs_ftfunction.cpp \
    ectclass.cpp \
    mypaintusb.cpp \
    mainwindow.cpp \
    mythreads.cpp \
    tdlasdialog.cpp \
    myshowwidget.cpp \
    glwidget.cpp \
    matlabhelper.cpp \
    mode.cpp


HEADERS  += mainwindow.h \
    cs_ftfunction.h \
    ftd2xx.h \
    tdlasdialog.h \
    mythreads.h \
    mypaintusb.h \
    ectclass.h \
    myshowwidget.h \
    glwidget.h \
    matlabhelper.h \
    mode.h

FORMS    += mainwindow.ui \
    tdlasdialog.ui



#LIBS += ftd2xx.dll

RESOURCES += \
    rsc.qrc

LIBS += LBP_Circular_ECT_16.lib \
    calderon_circle_16_electrodes_ssj.lib \
    calderon_circle_16_electrodes_ssjwq.lib


