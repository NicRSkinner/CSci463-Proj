#include "door.h"



Door::Door(bool inState, QRectF doorBounds, qreal inRotation) : QGraphicsObject()
{
    lock = inState;
    doorBoundary = doorBounds;
    //setParent(inObject);
    setFlag(GraphicsItemFlag::ItemIsSelectable, true);
    setRotation(inRotation);
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

    QRectF smallRect = QRectF(doorBoundary.left(), doorBoundary.top(), doorBoundary.width(), doorBoundary.height()/2);
    painter->setBrush(QBrush(Qt::red, Qt::BrushStyle::SolidPattern));
    painter->drawRect(smallRect);

    if (isSelected())
    {
        painter->setBrush(QBrush(Qt::black, Qt::BrushStyle::CrossPattern));
        painter->drawRect(doorBoundary);

        painter->setBrush(QBrush(Qt::green, Qt::BrushStyle::SolidPattern));
        painter->drawRect(smallRect);

    }


    //painter->drawRect
}

