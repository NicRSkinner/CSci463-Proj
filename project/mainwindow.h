#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "testbench.h"
#include "adminoptions.h"
#include "qtimer.h"
#include "QTime"
#include "QGraphicsScene"
#include "QGraphicsRectItem"
#include "QGraphicsView"
#include "graphicsviewzoom.h"
#include "room.h"

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

    void updateTime();

    void on_pushButtonLockdown_clicked();

    void on_pushButtonMasterUnlock_clicked();

    void on_pushButtonClearAlarms_clicked();

    void on_pushButtonCEmergencyS_clicked();

    void on_pushButtonAdminOptions_clicked();

    void RoomSelectionUpdated();

private:
    Ui::MainWindow *ui;
    testBench tb;
    AdminOptions adminoptions;
};

#endif // MAINWINDOW_H
