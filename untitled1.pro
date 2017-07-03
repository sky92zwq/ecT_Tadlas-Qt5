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
    mode.h \
    matlab/calderon_circle_12_electrodes_ssj.h \
    matlab/calderon_circle_12_electrodes_ssj_types.h \
    matlab/calderon_circle_16_electrodes_ssj.h \
    matlab/calderon_circle_16_electrodes_ssj_types.h \
    matlab/calderon_circle_32_electrodes_ssj.h \
    matlab/calderon_circle_32_electrodes_ssj_types.h \
    matlab/LBP_Circular_ECT_16.h \
    matlab/LBP_Circular_ECT_16_types.h \
    matlab/mat.h \
    matlab/matrix.h \
    matlab/rt_defines.h \
    matlab/rt_nonfinite.h \
    matlab/rtwtypes.h \
    matlab/tmwtypes.h \
    matlabdynamic/calderon_circle_16_electrodes_ssjwq.h \
    matlabdynamic/calderon_circle_16_electrodes_ssjwq_types.h \
    matlabdynamic/rt_defines.h \
    matlabdynamic/rt_nonfinite.h \
    matlabdynamic/rtwtypes.h

FORMS    += mainwindow.ui \
    tdlasdialog.ui



#LIBS += ftd2xx.dll

RESOURCES += \
    rsc.qrc

#LIBS += LBP_Circular_ECT_16.lib \
#    calderon_circle_16_electrodes_ssj.lib \
#    calderon_circle_16_electrodes_ssjwq.lib

DISTFILES += \
    matlabcoder \
    matlab/calderon_circle_12_electrodes_ssj.lib \
    matlab/calderon_circle_16_electrodes_ssj.lib \
    matlab/calderon_circle_32_electrodes_ssj.lib \
    matlab/LBP_Circular_ECT_16.lib \
    matlab/libmat.lib \
    matlab/libmx.lib \
    matlab/calderon_circle_12_electrodes_ssj.dll \
    matlab/calderon_circle_16_electrodes_ssj.dll \
    matlab/calderon_circle_32_electrodes_ssj.dll \
    matlab/LBP_Circular_ECT_16.dll \
    matlab/libmat.dll \
    matlab/libmx.dll \
    matlab/libut.dll \
    matlab/Sen_matrix_16.txt \
    matlabdynamic/calderon_circle_16_electrodes_ssjwq.lib \
    matlabdynamic/calderon_circle_16_electrodes_ssjwq.dll


