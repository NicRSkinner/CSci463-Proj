#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

    currentTimeout = 30;
    operatorTimeout = new QTimer();
    operatorTimeout->setInterval(1000);
    connect(operatorTimeout, &QTimer::timeout, this, &MainWindow::UpdateTimeout);
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
   {

       ui->labelSprinklerSystem->setText("");
       ui->labelSecurityAlarm->setText("");
       ui->labelGunTurrets->setText("");
       ui->labelElectricity->setText("");
       ui->labelSecurityAlarm->setText("");
       ui->labelFireAlarm->setText("");
       ui->labelOccupation->setText("");
       ui->labelSmokeAlarm->setText("");
       return;
    }
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
    tb.resetButton(1);
    operatorTimeout->stop();
    currentTimeout = 30;
    ui->labelOperatorTimeout->setText("30");
    ui->labelEmergencyServices->setText(" ");
}

void MainWindow::on_pushButtonCEmergencyS_clicked()
{
    // Send to incident log
    // contact method
    currentTimeout = 0;
    ui->labelOperatorTimeout->setText("0");
    ui->labelEmergencyServices->setText("Emergency Services Contacted");
}

void MainWindow::on_pushButtonAdminOptions_clicked()
{
    adminoptions.show();
}

void MainWindow::AlarmActivated()
{
    if (alarmActivated == true)
    {
        currentTimeout = 0;
        ui->labelOperatorTimeout->setText("0");
        ui->labelEmergencyServices->setText("Emergency Services Contacted");
    }
    else
    {
        operatorTimeout->start();
    }
}
/*
 * TODO: Finish timeout function
 *
*/
void MainWindow::UpdateTimeout()
{
    if (currentTimeout != 0)
    {
        currentTimeout--;
        ui->labelOperatorTimeout->setText(static_cast<QString>(currentTimeout));
    }
    else
    {
        // Call emergency services
        ui->labelEmergencyServices->setText(" ");
    }
}

void MainWindow::on_pushButtonTestStart_clicked()
{
    Zone *currZone;


    //fetching the total number of zones within the
    int total = ui->buildingViewMap->zones.count();

    if (ui->buildingViewMap->getSelectedRoom() == nullptr)
    {
        int random = rand() % total;
        currZone = ui->buildingViewMap->zones.at(random);
    }
    else
    {
        //Generates random zone number and sets that.
        int random = rand() % total;
        //currZone = ui->buildingViewMap->zones.at(random);
        currZone = dynamic_cast<Zone*>(ui->buildingViewMap->getSelectedRoom()->parent());
    }

    tb.resetButton(0);
    tb.addZone(currZone);
    tb.exec();
}
