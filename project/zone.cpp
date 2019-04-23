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

            rooms.append(new Room(QRectF(300/2, -2500/2, 900/2, 900/2), "Elevator", this));
            static_cast<BuildingView *>(inParent)->getMasterFloorScene().at(0)->addItem(rooms.at(roomIndex));
            roomIndex++;

        }
        if(inZone == 2)
        {


            rooms.append(new Room(QRectF(-1500/2, -2500/2, 1800/2, 1800/2), "Room 103", this));
            static_cast<BuildingView *>(inParent)->getMasterFloorScene().at(0)->addItem(rooms.at(roomIndex));
            roomIndex++;

            rooms.append(new Room(QRectF(-2000/2, -2500/2, 1200/2, 900/2), "Room 105", this));
            static_cast<BuildingView *>(inParent)->getMasterFloorScene().at(0)->addItem(rooms.at(roomIndex));
            roomIndex++;

            rooms.append(new Room(QRectF(-2000/2, -000/2, 1200/2, 900/2), "Room 106", this));
            static_cast<BuildingView *>(inParent)->getMasterFloorScene().at(0)->addItem(rooms.at(roomIndex));
            roomIndex++;

            rooms.append(new Room(QRectF(-2000/2, -800/2, 1200/2, 900/2), "Room 107", this));
            static_cast<BuildingView *>(inParent)->getMasterFloorScene().at(0)->addItem(rooms.at(roomIndex));
            roomIndex++;

        }
        //redrawDoors();
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
