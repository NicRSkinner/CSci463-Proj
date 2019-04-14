#include "testbench.h"
#include "ui_testbench.h"

testBench::testBench(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testBench)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
}

testBench::~testBench()
{
    delete ui;
}

void testBench::on_pushButtonClose_clicked()
{
    this->close();
}
