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
    Door(bool inState, QRectF doorBounds, qreal inRotation); //Default const
    void setLockState(bool lock);
    bool getLockState();
private:
   bool lock;
   QRectF doorBoundary;
   QRectF boundingRect() const override;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // DOOR_H
