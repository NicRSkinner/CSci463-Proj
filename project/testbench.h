#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <QDialog>

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

signals:
    void ready();

private slots:
    void on_pushButtonClose_clicked();
    //void trigger(); //This is what is going to be consumed. Once the timer timesout(signal) it will look for this emit

private:
    Ui::testBench *ui;
};

#endif // TESTBENCH_H
