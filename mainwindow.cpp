#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
