#ifndef TDLASDIALOG_H
#define TDLASDIALOG_H

#include <QDialog>

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
};

#endif // TDLASDIALOG_H
