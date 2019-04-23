#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include <QList>
#include "door.h"
#include <QGraphicsObject>
#include <QRectF>
#include <qpainter.h>
#include <QtMath>

class Room : public QGraphicsObject
{
    Q_OBJECT
private:
    bool signs;
    //QList<Door> doors;
    //void addDoor(Door door);
    QRectF roomBoundary;
    QList<Door *> doors;
    int doorIndex;

    bool fireAlarmState;
    bool smokeAlarmState;
    bool securityAlarmState;

    void checkAlarmState(bool state);

public:
    void setFireAlarmState(bool inState);
    bool getFireAlarmState();

    void setSmokeAlarmState(bool inState);
    bool getSmokeAlarmState();

    void setSecurityAlarmState(bool inState);
    bool getSecurityAlarmState();
    void clearAlarms();
    void setSigns(bool inVal);


    explicit Room(QRectF roomBounds, QString inName, QObject *inParent);
    //Room(const Room &obj);
    //explicit Room(QWidget *parent = nullptr);
    void activateSecurityAlarm();
    void activateFireAlarm();
    void deactivateSecurityAlarm();
    void deactivateFireAlarm();
    void setSign(bool sign);
    bool getSign();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void paint();
    bool addDoor(Door *inDoor);
    bool unlockDoors();
    bool lockDoors();
    QString name;
    void redrawDoors();



    //QList<Door> getDoors(); //Blanking on how classes work in header files


signals:
    void alarmSet();

public slots:
};

#endif // ROOM_H
