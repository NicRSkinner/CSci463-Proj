#include "room.h"
#include "buildingview.h"
#include <QGraphicsItemGroup>

//bool securityAlarm, fireAlarm, signs;


Room::Room(QRectF roomBounds, QString inName, QObject *inParent) : QGraphicsObject()
{

    // TODO : FINISH CONSTRUCTOR
    //    setSecurityAlarm(inSecAlarm);
    //    setAlarm(inFireAlarm);
    //    setZone(inZone);
    doorIndex = 0;
    if(inName.compare("Room 102") == 0)
    {
        doors.append(new Door(true, (QRectF(-800/2, -800/2, 500/2, 200/2)), 0, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        doorIndex++;

        doors.append(new Door(true, (QRectF(-900/2, -900/2, 500/2, 200/2)), 90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        doorIndex++;
            //testDoor2 = new Door(true, (QRectF(-900/2, -900/2, 500/2, 200/2)), 90, rooms.at(0));
            //floorScenes.at(0)->addItem(testDoor2);
            //rooms.at(0)->addDoor(testDoor2);
    }
    if(inName.compare("Room 103") == 0)
    {

        doors.append(new Door(true, (QRectF(1000/2, -1500/2, 500/2, 200/2)), -90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        //testDoor3 = new Door(true, (QRectF(1000/2, -1500/2, 500/2, 200/2)), -90, rooms.at(1));
        //floorScenes.at(0)->addItem(testDoor3);
        //rooms.at(1)->addDoor(testDoor3);
        doorIndex++;
    }

    securityAlarm = false;
    roomBoundary = roomBounds;
    name = inName;
    setParent(inParent);
    setFlag(GraphicsItemFlag::ItemIsSelectable, true);
}

void Room::redrawDoors()
{
    for (int i = 0; i < doors.length(); i++)
    {
        doors.at(i)->reDraw();
    }
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

    painter->setBrush(QBrush(Qt::gray, Qt::BrushStyle::SolidPattern));

    painter->drawRect(roomBoundary);
    if (isSelected())
    {
        //lockDoors();
        painter->setBrush(QBrush(Qt::black, Qt::BrushStyle::CrossPattern));
        painter->drawRect(roomBoundary);
    }
    else {
        //unlockDoors();
    }
    painter->drawText(static_cast<int>(roomBoundary.x() + roomBoundary.width() / 2), static_cast<int>(roomBoundary.y() + roomBoundary.height() / 2), 300, 80, Qt::TextFlag::TextShowMnemonic, "test");
}

bool Room::addDoor(Door *inDoor)
{
    doors.append(inDoor);
    return true;
}

bool Room::lockDoors()
{
    for( int i=0; i<doors.count(); ++i )
    {
        doors.at(i)->setLockState(true);
    }
    return true;
}

bool Room::unlockDoors()
{
    for( int i=0; i<doors.count(); ++i )
    {
        doors.at(i)->setLockState(false);
    }
    return true;
}

void Room::clearAlarms()
{
    for(int i = 0; i < doors.length(); i++)
    doors.at(i)->clearAlarms();
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
