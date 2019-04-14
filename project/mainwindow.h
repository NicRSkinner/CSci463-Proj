#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "testbench.h"
#include "adminoptions.h"
#include "qtimer.h"
#include "QTime"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSystem_Test_GUI_triggered();

    void on_pushButton_8_clicked();

    void updateTime();

private:
    Ui::MainWindow *ui;
    testBench tb;
    AdminOptions adminoptions;


};

#endif // MAINWINDOW_H
