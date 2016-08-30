#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createToolBars();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->setUpdatesEnabled(true);
}

void MainWindow::on_lineEdit_editingFinished()
{
    QString strread;
    strread = ui->lineEdit->text();
    ui->listWidget->setUpdatesEnabled(false);
    ui->listWidget->addItem(strread);

}

void MainWindow::on_open_clicked()
{
    QString num;
    num=QString::number( usb.getnumDEv());
    ui->listWidget_2->addItem(num);

    QString label;
    if(!usb.isopened()){
        label+=usb.status.at(usb.Open(0));
        ui->listWidget_2->addItem(label);
    }
    else
        ui->listWidget_2->addItem("device 0 is allrdeay opened");
}

void MainWindow::on_close_clicked()
{
    QString label;
    if(usb.isopened()){

        label+=usb.status.at(usb.Close());
        ui->listWidget_2->addItem(label);
    }
    else
        ui->listWidget_2->addItem("device 0 is allrdeay closed");
}
void MainWindow::createToolBars()
{
    toolusb=addToolBar("usb");
}
