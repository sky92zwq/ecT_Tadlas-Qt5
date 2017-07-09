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
    mode.cpp \
    tdlasclass.cpp \
    Tikhonov/div.c \
    Tikhonov/eml_rand_mt19937ar_stateful.c \
    Tikhonov/eye.c \
    Tikhonov/landweber.c \
    Tikhonov/norm.c \
    Tikhonov/normest.c \
    Tikhonov/rand.c \
    Tikhonov/rt_nonfinite.c \
    Tikhonov/rtGetInf.c \
    Tikhonov/rtGetNaN.c \
    Tikhonov/Tikhonov.c \
    Tikhonov/Tikhonov_data.c \
    Tikhonov/Tikhonov_initialize.c \
    Tikhonov/Tikhonov_terminate.c \
    Tikhonov/xgemv.c


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
    matlabdynamic/rtwtypes.h \
    tdlasclass.h \
    rwhelper.h \
    Tikhonov/div.h \
    Tikhonov/eml_rand_mt19937ar_stateful.h \
    Tikhonov/eye.h \
    Tikhonov/landweber.h \
    Tikhonov/norm.h \
    Tikhonov/normest.h \
    Tikhonov/rand.h \
    Tikhonov/rt_nonfinite.h \
    Tikhonov/rtGetInf.h \
    Tikhonov/rtGetNaN.h \
    Tikhonov/rtwtypes.h \
    Tikhonov/Tikhonov.h \
    Tikhonov/Tikhonov_data.h \
    Tikhonov/Tikhonov_initialize.h \
    Tikhonov/Tikhonov_terminate.h \
    Tikhonov/Tikhonov_types.h \
    Tikhonov/xgemv.h

FORMS    += mainwindow.ui \
    tdlasdialog.ui



#LIBS += ftd2xx.dll

RESOURCES += \
    rsc.qrc

LIBS += LBP_Circular_ECT_16.lib \
    ./calderon_circle_16_electrodes_ssj.lib \
    ./calderon_circle_16_electrodes_ssjwq.lib \
    ./Tikhonov.lib

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
    matlabdynamic/calderon_circle_16_electrodes_ssjwq.dll \
    Tikhonov/Tikhonov.lib \
    Tikhonov/Tikhonov.dll

