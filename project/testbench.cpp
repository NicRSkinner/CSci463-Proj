#include "testbench.h"
#include "ui_testbench.h"
#include "door.h"
#include <QTimer>
#include <QDebug>

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
    this->triggerAlarm();
    //connect(this, SIGNAL(ready()), this, SLOT(close()));
    // Initial test, closes program after 10 seconds
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(triggerAlarm()));
    timer->start(2000); //Ready to emit signal
    qDebug() << "Singleshot";
    //QTimer::singleShot(1000, this, SLOT(triggerAlarm()));



    //This is to trigger alarm after x seconds
    //connect(timer, SIGNAL(timeout()), this, SLOT(triggerAlarm()));
    //timer->start(1000);



}


void testBench::triggerAlarm() {

    if(reset == 0) {
        qDebug() << "Here next closing";
        if(currZone == nullptr) {
            qDebug() << "No init";
            return;
        }
        int number = currZone->rooms.count();
        qDebug() << "Number of rooms: " << number;
        int randomRoom = rand() % number;

        //currZone->rooms.at(randomRoom)->unlockDoors();
        currZone->rooms.at(randomRoom)->setFireAlarmState(true);
    } else {
        qDebug() << "Reset button pressed.";
    }

}

void testBench::lockDoor() {

}

void testBench::addZone(Zone *currentZone)
{
    currZone = currentZone;
}

void testBench::resetButton(int val) {
    reset = val;
}
