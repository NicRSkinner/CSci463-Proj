#ifndef ZONE_H
#define ZONE_H

#include <QList>
#include <QObject>
#include "room.h"
//#include "buildingview.h"

class Zone : public QObject
{
    Q_OBJECT
public:
    Zone(QObject *inParent, int inZone);
    bool setMasterAlarm(bool inAlarmState);
    bool lockAllDoors();
    QList<Room *> rooms;
    void unlockDoors();

private:
    bool masterAlarm;
    //QList<Room> roomsList;
    int roomIndex;
    void redrawDoors();
};
#endif // ZONE_H
