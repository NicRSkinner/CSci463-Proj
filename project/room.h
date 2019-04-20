#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include <QList>
#include "door.h"
#include <QGraphicsObject>
#include <QRectF>
#include <qpainter.h>

class Room : public QGraphicsObject
{
    Q_OBJECT
private:
    bool securityAlarm, fireAlarm, signs;
    //QList<Door> doors;
    //void addDoor(Door door);
    QRectF roomBoundary;
public:
    explicit Room(QRectF roomBounds);
    //Room(const Room &obj);
    //explicit Room(QWidget *parent = nullptr);
    void activateSecurityAlarm();
    void activateFireAlarm();
    void deactivateSecurityAlarm();
    void deactivateFireAlarm();
    void setSign(bool sign);
    bool getSign();
    bool getFireAlarmState();
    bool getSecurityAlarmState();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


    //QList<Door> getDoors(); //Blanking on how classes work in header files


signals:

public slots:
};

#endif // ROOM_H
