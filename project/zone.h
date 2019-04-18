#ifndef ZONE_H
#define ZONE_H

#include <QList>
#include <QObject>
#include "room.h"

class Zone : public QObject
{
    Q_OBJECT
public:
    Zone();
    bool setMasterAlarm(bool inAlarmState);

private:
    bool masterAlarm;
    //QList<Room> roomsList;
};
#endif // ZONE_H
