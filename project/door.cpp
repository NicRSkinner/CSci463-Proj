#include "door.h"



Door::Door(bool inState, QRectF doorBounds) : QGraphicsObject()
{
    lock = inState;
    doorBoundary = doorBounds;
}

void Door::setLockState(bool value) {
    lock = value;
}

bool Door::getLockState() {
    return lock;
}


QRectF Door::boundingRect() const
{
    return doorBoundary;
}

void Door::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(QBrush(Qt::blue, Qt::BrushStyle::SolidPattern));

    painter->drawRect(doorBoundary);

    if (isSelected())
    {
        painter->setBrush(QBrush(Qt::black, Qt::BrushStyle::CrossPattern));
        painter->drawRect(doorBoundary);
    }


    //painter->drawRect
}

