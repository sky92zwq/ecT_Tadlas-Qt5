#include "tdlasdialog.h"
#include "ui_tdlasdialog.h"

tdlasDialog::tdlasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tdlasDialog)
{
    ui->setupUi(this);
}

tdlasDialog::~tdlasDialog()
{
    delete ui;
}
