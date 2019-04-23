#include "zone.h"
#include "buildingview.h"
#include <QGraphicsItemGroup>

Zone::Zone(QObject *inParent, int inZone)
{
   setParent(inParent);
   masterAlarm = false;
   roomIndex = 0;
   //If we are in zone 1
    if(inZone == 1)
    {
        //Add rooms for zone 1
        rooms.append(new Room(QRectF(-900/2, -900/2, 1800/2, 1800/2), "Room 102", this));
        //floorScenes.at(0)->addItem(zones.at(0)->rooms.at(0));
        static_cast<BuildingView *>(inParent)->getMasterFloorScene().at(0)->addItem(rooms.at(roomIndex));
        roomIndex++;
               // addItem(zones.at(0)->rooms.at(0));
    }
    if(inZone == 2)
    {
        rooms.append(new Room(QRectF(-1500/2, -2500/2, 1800/2, 1800/2), "Room 103", this));
        static_cast<BuildingView *>(inParent)->getMasterFloorScene().at(0)->addItem(rooms.at(roomIndex));
        roomIndex++;

    }
    //redrawDoors();

    connect(this, SIGNAL(alarmActivated()), inParent, SLOT(AlarmActivated()));
}

void Zone::redrawDoors()
{
   for (int i = 0; i < rooms.length(); i++)
   {
       rooms.at(i)->redrawDoors();
   }
}

bool Zone::setMasterAlarm(bool inAlarmState)
{
   masterAlarm = inAlarmState;
   return true;
}

bool Zone::lockAllDoors()
{
    for(int i = 0; i < rooms.length(); i++)
    rooms.at(i)->lockDoors();
    return true;
}

void Zone::unlockDoors()
{
    for(int i = 0; i < rooms.length(); i++)
    rooms.at(i)->unlockDoors();
}

void Zone::clearAlarms()
{
    for(int i = 0; i < rooms.length(); i++)
    rooms.at(i)->clearAlarms();
}

void Zone::alarmSignal()
{
    emit alarmActivated();
}
