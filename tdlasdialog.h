#ifndef TDLASDIALOG_H
#define TDLASDIALOG_H

#include <QDialog>
#include "cs_ftfunction.h"
#include "mainwindow.h"
#include <qmessagebox.h>
#include <qsizepolicy.h>

namespace Ui {
class tdlasDialog;
}

class tdlasDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tdlasDialog(QWidget *parent = 0);
    ~tdlasDialog();

private:
    Ui::tdlasDialog *ui;
    CS_ftfunction *usb;
public slots:
    void acceptusb(CS_ftfunction *u);
private slots:
    void on_lazer1openclose_clicked();
    bool setlazeropen(quint16 lazer);
    bool setlazerclose(quint16 lazer);

    void on_setlazer1tc_clicked();

    void on_das_clicked(bool checked);

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_wms_clicked(bool checked);

private:
    bool lazerneedopen;
public:
    enum measurement{
        null,
        das,
        wms
    };
    measurement measure;
signals:
    void mystatus(QString &str);
};

#endif // TDLASDIALOG_H
