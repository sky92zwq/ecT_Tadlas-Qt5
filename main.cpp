#include "mainwindow.h"
#include <QApplication>
#include "cs_ftfunction.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
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
