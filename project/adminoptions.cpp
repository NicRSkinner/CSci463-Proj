#include "adminoptions.h"
#include "ui_adminoptions.h"

AdminOptions::AdminOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminOptions)
{
    ui->setupUi(this);
}

AdminOptions::~AdminOptions()
{
    delete ui;
}

void AdminOptions::on_pushButtonExitDialog_clicked()
{
    this->close();
}
