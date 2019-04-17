#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include <QList>
#include "door.h"

class Room : public QObject
{
    Q_OBJECT
private:
    bool securityAlarm, fireAlarm, signs;
    QList<Door> doors;
   // Zone *zone;
   // void setZone(Zone zone);
    void addDoor(Door door);
public:
    explicit Room(QWidget *parent = nullptr);
    void activateSecurityAlarm();
    void activateFireAlarm();
    void deactivateSecurityAlarm();
    void deactivateFireAlarm();
    void setSign(bool sign);
    bool getSign();
    bool getFireAlarmState();
    bool getSecurityAlarmState();
    QList<Door> getDoors(); //Blanking on how classes work in header files
    //Zone getZone(); //Also I think im googling wrong queries cuz I cant find an example


signals:

public slots:
};

#endif // ROOM_H
