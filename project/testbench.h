#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <QDialog>
#include "zone.h"

namespace Ui {
class testBench;
}

class testBench : public QDialog
{
    Q_OBJECT

public:
    explicit testBench(QWidget *parent = nullptr);
    void programLoop();
    ~testBench();

    void addZone(Zone *currentZone);

signals:
    void ready();

private slots:
    void on_pushButtonClose_clicked();
    void triggerAlarm();
    void lockDoor();
    //void trigger(); //This is what is going to be consumed. Once the timer timesout(signal) it will look for this emit

private:
    Ui::testBench *ui;
    Zone *currZone;
};

#endif // TESTBENCH_H
