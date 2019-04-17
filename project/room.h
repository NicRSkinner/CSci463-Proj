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
    //QList<Door> doors;
    void addDoor(Door door);
public:
    Room();
    //explicit Room(QWidget *parent = nullptr);
    void activateSecurityAlarm();
    void activateFireAlarm();
    void deactivateSecurityAlarm();
    void deactivateFireAlarm();
    void setSign(bool sign);
    bool getSign();
    bool getFireAlarmState();
    bool getSecurityAlarmState();
    //QList<Door> getDoors(); //Blanking on how classes work in header files


signals:

public slots:
};

#endif // ROOM_H
