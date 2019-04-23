#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QGraphicsObject>
#include <QRectF>
#include <qpainter.h>


class Door : public QGraphicsObject
{
    Q_OBJECT

public:
    Door(bool inState, QRectF doorBounds, qreal inRotation, QGraphicsObject *inParent); //Default const
    void setLockState(bool lock);
    bool getLockState();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void reDraw();

    void setFireAlarmState(bool lock);
    bool getFireAlarmState();

    void setSmokeAlarmState(bool lock);
    bool getSmokeAlarmState();

    void setSecurityAlarmState(bool lock);
    bool getSecurityAlarmState();

private:
   bool lock;
   QRectF doorBoundary;
   QRectF boundingRect() const override;
   QString name;


   QPainter *painter;
   const QStyleOptionGraphicsItem *option;
   QWidget *widget;
    bool fireAlarmState;
    bool smokeAlarmState;
    bool securityAlarmState;

};

#endif // DOOR_H
