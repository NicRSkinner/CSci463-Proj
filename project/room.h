#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include <QList>
#include "door.h"
#include "QGraphicsRectItem"
#include "QGraphicsTextItem"
#include <QGraphicsObject>

class Room : public QGraphicsObject
{
    Q_OBJECT
private:
    bool securityAlarm, fireAlarm, signs;
    //QList<Door> doors;
    void addDoor(Door door);
    QGraphicsRectItem *graphicsRoomRectangle;
public:
    // Left x, top y, width, height
    Room(QGraphicsRectItem *roomRectangle);
    //explicit Room(QWidget *parent = nullptr);
    void activateSecurityAlarm();
    void activateFireAlarm();
    void deactivateSecurityAlarm();
    void deactivateFireAlarm();
    void setSign(bool sign);
    bool getSign();
    bool getFireAlarmState();
    bool getSecurityAlarmState();
    QGraphicsRectItem* getRoomGraphicsItem();


    //QList<Door> getDoors(); //Blanking on how classes work in header files


signals:

public slots:
};

#endif // ROOM_H
