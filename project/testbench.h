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
    ~testBench();

private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::testBench *ui;
};

#endif // TESTBENCH_H
