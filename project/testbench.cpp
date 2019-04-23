#include "testbench.h"
#include "ui_testbench.h"
#include "door.h"
#include <QTimer>

testBench::testBench(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testBench)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    this->programLoop();
}

testBench::~testBench()
{
    delete ui;
}

void testBench::on_pushButtonClose_clicked()
{

    this->close();
}

void testBench::programLoop() {
    //Need to set up the QTimer

    //Create class instant for each object



    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButtonClose_clicked()));
    timer->start(10000); //Ready to emit signal
    emit ready();

}
