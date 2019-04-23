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
    bool lockAllDoor();
    QList<Room *> rooms;

private:
    bool masterAlarm;
    //QList<Room> roomsList;
    int roomIndex;
};
#endif // ZONE_H
