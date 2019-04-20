#include "room.h"

//bool securityAlarm, fireAlarm, signs;


Room::Room(QRectF roomBounds) : QGraphicsObject()
{

    // TODO : FINISH CONSTRUCTOR
    //    setSecurityAlarm(inSecAlarm);
    //    setAlarm(inFireAlarm);
    //    setZone(inZone);

    securityAlarm = false;
    roomBoundary = roomBounds;
    setFlag(GraphicsItemFlag::ItemIsSelectable, true);
}
/*
Room::Room(const Room &obj)
{
    securityAlarm = obj.securityAlarm;
    roomBoundry = obj.roomBoundry;
    signs = obj.signs;
    fireAlarm = obj.fireAlarm;
}
*/
void Room::activateFireAlarm() {
    fireAlarm = true;
}
void Room::deactivateFireAlarm() {
    fireAlarm = false;
}

void Room::activateSecurityAlarm() {
    securityAlarm = true;
}

void Room::deactivateSecurityAlarm() {
    securityAlarm = false;
}

void Room::setSign(bool sign) {
    signs = sign;
}

bool Room::getSecurityAlarmState() {
    return securityAlarm;
}

bool Room::getFireAlarmState(){
    return fireAlarm;
}

QRectF Room::boundingRect() const
{
    return roomBoundary;
}

void Room::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(QBrush(Qt::blue, Qt::BrushStyle::SolidPattern));

    painter->drawRect(roomBoundary);

    if (isSelected())
    {
        painter->setBrush(QBrush(Qt::black, Qt::BrushStyle::CrossPattern));
        painter->drawRect(roomBoundary);
    }
    painter->drawText(static_cast<int>(roomBoundary.x() + roomBoundary.width() / 2), static_cast<int>(roomBoundary.y() + roomBoundary.height() / 2), 300, 80, Qt::TextFlag::TextShowMnemonic, "test");
}

/*
void Room::addDoor(Door door) {
    //instanciate door
    //door = ;
    //doors.append(door);
}

QList<Door> Room::getDoors() {
    //return door
    return doors;
}
*/
