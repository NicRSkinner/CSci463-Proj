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
private:
   bool lock;
   QRectF doorBoundary;
   QRectF boundingRect() const override;


   QPainter *painter;
   const QStyleOptionGraphicsItem *option;
   QWidget *widget;

};

#endif // DOOR_H
