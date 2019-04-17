#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include "door.h"
#include "zone.h"

class Room : public QObject
{
private:
    bool securityAlarm, fireAlarm, signs, controlRoom;
    void setZone(Zone zone);
    void setDoor(Door door);
public:
    //explicit Room(QWidget *parent = nullptr);
    void setSecurityAlarm(bool value);
    void setFireAlarm(bool value);
    void setSign(bool sign);
    void setControlRoom(bool control);
    bool getSign();
    bool getSecurityAlarm();
    bool getFireAlarm();
    Door getDoor(); //Blanking on how classes work in header files
    Zone getZone(); //Also I think im googling wrong queries cuz I cant find an example
    bool getControlRoom();


signals:

public slots:
};

#endif // ROOM_H
