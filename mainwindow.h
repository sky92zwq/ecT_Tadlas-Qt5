#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cs_ftfunction.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CS_ftfunction usb;

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_open_clicked();

    void on_close_clicked();
private:
    void createToolBars();

private:
    Ui::MainWindow *ui;
private:
    QToolBar *toolusb;

};

#endif // MAINWINDOW_H
