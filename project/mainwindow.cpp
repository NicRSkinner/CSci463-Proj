#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::updateTime();
    QTimer *t = new QTimer(this);
    t->setInterval(1000);
    connect(t, &QTimer::timeout, this, &MainWindow::updateTime);
    t->start();
}

void MainWindow::updateTime()
{
    QString time1 = QTime::currentTime().toString("HH:mm");
    ui->labelTime->setText(time1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSystem_Test_GUI_triggered()
{
    tb.exec();
}


void MainWindow::on_pushButtonLockdown_clicked()
{

}

void MainWindow::on_pushButtonMasterUnlock_clicked()
{

}

void MainWindow::on_pushButtonClearAlarms_clicked()
{

}

void MainWindow::on_pushButtonCEmergencyS_clicked()
{

}

void MainWindow::on_pushButtonAdminOptions_clicked()
{
    adminoptions.show();
}
