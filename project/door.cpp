#include "door.h"



Door::Door(bool inState, QRectF doorBounds, qreal inRotation, QGraphicsObject *inParent) : QGraphicsObject()
{
    lock = inState;
    doorBoundary = doorBounds;
    //setParent(inObject);
    setFlag(GraphicsItemFlag::ItemIsSelectable, false);
    setRotation(inRotation);
    setParent(inParent);
}

void Door::reDraw()
{
    //this->update();
    //paint(painter, nullptr, nullptr);
}
void Door::setLockState(bool value) {
    lock = value;
    update();
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
    //this->painter = painter;
    painter->setBrush(QBrush(Qt::blue, Qt::BrushStyle::SolidPattern));

    painter->drawRect(doorBoundary);

    QRectF smallRect = QRectF(doorBoundary.left(), doorBoundary.top(), doorBoundary.width(), doorBoundary.height()/2);
    painter->setBrush(QBrush(Qt::red, Qt::BrushStyle::SolidPattern));
    painter->drawRect(smallRect);

    if (isSelected())
    {
        painter->setBrush(QBrush(Qt::black, Qt::BrushStyle::CrossPattern));
        painter->drawRect(doorBoundary);
        //parentObject()->setSelected(true);
        //this->setSelected(false);
    }

    if(getLockState())
    {
        painter->setBrush(QBrush(Qt::red, Qt::BrushStyle::SolidPattern));
        painter->drawRect(smallRect);
    }
    else {
        painter->setBrush(QBrush(Qt::green, Qt::BrushStyle::SolidPattern));
        painter->drawRect(smallRect);
    }


    //painter->drawRect
}

