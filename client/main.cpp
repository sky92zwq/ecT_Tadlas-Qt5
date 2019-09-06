#include "mainwindow.h"
#include <QApplication>
#include "cs_ftfunction.h"
#include <QDebug>

#include <QDesktopWidget>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    if (QCoreApplication::arguments().contains(QStringLiteral("--multisample")))
        fmt.setSamples(4);
    if (QCoreApplication::arguments().contains(QStringLiteral("--coreprofile"))) {
        fmt.setVersion(3, 2);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
    }
    QSurfaceFormat::setDefaultFormat(fmt);

    MainWindow w;
    if (QCoreApplication::arguments().contains(QStringLiteral("--transparent"))) {
        w.setAttribute(Qt::WA_TranslucentBackground);
        w.setAttribute(Qt::WA_NoSystemBackground, false);
    }
    //setLayout();
    w.show();
    /*
     * 封装类CS_ftfunction完成usb的常用功能
    */
//    CS_ftfunction myusb;
//    qDebug()<<myusb.Open(0);
    /*
    */
//    qDebug()<<myusb.getnumDEv();

    return a.exec();
}
