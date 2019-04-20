#include "room.h"

//bool securityAlarm, fireAlarm, signs;


Room::Room(QRectF roomBounds) : QGraphicsObject()
{

    // TODO : FINISH CONSTRUCTOR
    //    setSecurityAlarm(inSecAlarm);
    //    setAlarm(inFireAlarm);
    //    setZone(inZone);

    securityAlarm = false;
    roomBoundry = roomBounds;
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
    return roomBoundry;
}

void Room::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::blue, Qt::BrushStyle::SolidPattern));

    painter->drawRect(roomBoundry);

    if (isSelected())
    {
        painter->setBrush(QBrush(Qt::black, Qt::BrushStyle::BDiagPattern));
        painter->drawRect(roomBoundry);
    }
    else
    {
        painter->setBrush(QBrush(Qt::blue, Qt::BrushStyle::SolidPattern));
    }


    //painter->drawRect
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
