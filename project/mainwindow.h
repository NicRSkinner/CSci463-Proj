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
#include "QGridLayout"

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

private:
    Ui::MainWindow *ui;
    testBench tb;
    AdminOptions adminoptions;
    QGraphicsScene scene;
    QBrush blueBrush = QBrush(Qt::blue, Qt::BrushStyle::SolidPattern);
    QPen blackPen = QPen(Qt::black);
    QGraphicsRectItem *rect = scene.addRect(QRectF(-50, -50, 100, 100));


};

#endif // MAINWINDOW_H
