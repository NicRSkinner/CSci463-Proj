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
    //connect(ui->graphicsViewMap, SIGNAL(selectionChanged()), this, SLOT(roomSelectionUpdated()));

    connect(ui->buildingViewMap, SIGNAL(activateAlarm()), this, SLOT(AlarmActivated()));
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

}

void MainWindow::RoomSelectionUpdated()
{
   //This gets updated every time the selection is changed in the buildingview
   Room *selectedRoom = ui->buildingViewMap->getSelectedRoom(); // will return a pointer to a room object, which is null if nothing is selected
   //ui->labelTimeSTATIC->setText("TEST");

   if (selectedRoom == nullptr)
       return;

   if (selectedRoom->getFireAlarmState())
   {
       ui->labelSprinklerSystem->setText("Activated");
   }
   else
   {
       ui->labelSprinklerSystem->setText("Deactivated");
   }

   if (selectedRoom->getSecurityAlarmState())
   {
       ui->labelSecurityAlarm->setText("Activated");
   }
   else
   {
       ui->labelSecurityAlarm->setText("Deactivated");
   }

   ui->labelGunTurrets->setText("Activated");

   // Electricity
   if (selectedRoom->getFireAlarmState())
   {
       ui->labelElectricity->setText("Activated");
   }
   else
   {
       ui->labelElectricity->setText("Deactivated");
   }

   // Fire Alarm
   if (selectedRoom->getFireAlarmState())
   {
       ui->labelFireAlarm->setText("Activated");
   }
   else
   {
       ui->labelFireAlarm->setText("Deactivated");
   }

   // Smoke Alarm
   if (selectedRoom->getSmokeAlarmState())
   {
       ui->labelSmokeAlarm->setText("Activated");
   }
   else
   {
       ui->labelSmokeAlarm->setText("Deactivated");
   }

   // Security Alarm
   if (selectedRoom->getSecurityAlarmState())
   {
       ui->labelSecurityAlarm->setText("Activated");
   }
   else
   {
       ui->labelSecurityAlarm->setText("Deactived");
   }
   // Occupation

   ui->labelOccupation->setText("No Occupation");

}

void MainWindow::on_pushButtonLockdown_clicked()
{
    ui->buildingViewMap->masterLockdown();
}

void MainWindow::on_pushButtonMasterUnlock_clicked()
{
    ui->buildingViewMap->masterUnlock();
}

void MainWindow::on_pushButtonClearAlarms_clicked()
{
    ui->buildingViewMap->clearAlarms();
}

void MainWindow::on_pushButtonCEmergencyS_clicked()
{
    // Send to incident log
    // contact method
}

void MainWindow::on_pushButtonAdminOptions_clicked()
{
    adminoptions.show();
}

void MainWindow::AlarmActivated()
{
    QTimer *t = new QTimer(this);
    t->setInterval(1000);
    connect(t, &QTimer::timeout, this, &MainWindow::UpdateTimeout);
    t->start();
}

void MainWindow::UpdateTimeout()
{

}

void MainWindow::on_pushButtonTestStart_clicked()
{
    Zone *currZone;
    if (ui->buildingViewMap->getSelectedRoom() == nullptr)
    {
        currZone = ui->buildingViewMap->zones.at(0);
    }
    else
    {
        currZone = dynamic_cast<Zone*>(ui->buildingViewMap->getSelectedRoom()->parent());
    }

    tb.addZone(currZone);
    tb.exec();
}
