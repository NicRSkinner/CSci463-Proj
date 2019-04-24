#include "room.h"
#include "buildingview.h"
#include <QGraphicsItemGroup>
#include "zone.h"

//bool securityAlarm, fireAlarm, signs;


Room::Room(QRectF roomBounds, QString inName, QObject *inParent) : QGraphicsObject()
{
    setParent(inParent);
    // TODO : FINISH CONSTRUCTOR
    //    setSecurityAlarm(inSecAlarm);
    //    setAlarm(inFireAlarm);
    //    setZone(inZone);
    doorIndex = 0;
    if(inName.compare("Room 102") == 0)
    {
        setRoomNumber(102);
        doors.append(new Door(true, (QRectF(-800/2, -800/2, 250/2, 100/2)), 0, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        doorIndex++;

        doors.append(new Door(true, (QRectF(-900/2, -900/2, 250/2, 100/2)), 90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        doorIndex++;
            //testDoor2 = new Door(true, (QRectF(-900/2, -900/2, 500/2, 200/2)), 90, rooms.at(0));
            //floorScenes.at(0)->addItem(testDoor2);
            //rooms.at(0)->addDoor(testDoor2);
    }
    if(inName.compare("Room 103") == 0)
    {
        setRoomNumber(103);
        doors.append(new Door(true, (QRectF(1000/2, -1500/2, 250/2, 100/2)), -90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        //testDoor3 = new Door(true, (QRectF(1000/2, -1500/2, 500/2, 200/2)), -90, rooms.at(1));
        //floorScenes.at(0)->addItem(testDoor3);
        //rooms.at(1)->addDoor(testDoor3);
        doorIndex++;
    }
    if(inName.compare("Room 105") == 0)
    {
        setRoomNumber(105);
        doors.append(new Door(true, (QRectF(-1900/2, 800/2, 250/2, 100/2)), 90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        doorIndex++;
    }
    if(inName.compare("Room 107") == 0)
    {
        setRoomNumber(107);
        doors.append(new Door(true, (QRectF(-600/2, 800/2, 250/2, 100/2)), 90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        doorIndex++;
    }

    if(inName.compare("Room 106") == 0)
    {
        setRoomNumber(106);
        doors.append(new Door(true, (QRectF(100/2, 800/2, 250/2, 100/2)), 90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        doorIndex++;
    }

    if(inName.compare("Elevator 1") == 0)
    {
        setRoomNumber(1);
        doors.append(new Door(true, (QRectF(1900/2, 300/2, 250/2, 100/2)), -90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor1()->addToGroup(doors.at(doorIndex));
        doorIndex++;
    }

   //For floor 2
    if(inName.compare("Room 202") == 0)
    {
        setRoomNumber(202);
        doors.append(new Door(true, (QRectF(-800/2, -800/2, 250/2, 100/2)), 0, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor2()->addToGroup(doors.at(doorIndex));
        doorIndex++;

        doors.append(new Door(true, (QRectF(-900/2, -900/2, 250/2, 100/2)), 90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor2()->addToGroup(doors.at(doorIndex));
        doorIndex++;
            //testDoor2 = new Door(true, (QRectF(-900/2, -900/2, 500/2, 200/2)), 90, rooms.at(0));
            //floorScenes.at(0)->addItem(testDoor2);
            //rooms.at(0)->addDoor(testDoor2);
    }
    if(inName.compare("Room 203") == 0)
    {
        setRoomNumber(203);
        doors.append(new Door(true, (QRectF(1000/2, -1500/2, 250/2, 100/2)), -90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor2()->addToGroup(doors.at(doorIndex));


        //testDoor3 = new Door(true, (QRectF(1000/2, -1500/2, 500/2, 200/2)), -90, rooms.at(1));
        //floorScenes.at(0)->addItem(testDoor3);
        //rooms.at(1)->addDoor(testDoor3);
        doorIndex++;
    }
    if(inName.compare("Room 205") == 0)
    {
        setRoomNumber(205);
        doors.append(new Door(true, (QRectF(-1900/2, 800/2, 250/2, 100/2)), 90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor2()->addToGroup(doors.at(doorIndex));
        doorIndex++;
    }
    if(inName.compare("Room 207") == 0)
    {
        setRoomNumber(207);
        doors.append(new Door(true, (QRectF(-600/2, 800/2, 250/2, 100/2)), 90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor2()->addToGroup(doors.at(doorIndex));
        doorIndex++;
    }

    if(inName.compare("Room 206") == 0)
    {
        setRoomNumber(206);
        doors.append(new Door(true, (QRectF(100/2, 800/2, 250/2, 100/2)), 90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor2()->addToGroup(doors.at(doorIndex));
        doorIndex++;
    }

    if(inName.compare("Elevator 2") == 0)
    {
        setRoomNumber(2);
        doors.append(new Door(true, (QRectF(1900/2, 300/2, 250/2, 100/2)), -90, this));
        static_cast<BuildingView *>(inParent->parent())->getFloor2()->addToGroup(doors.at(doorIndex));
        doorIndex++;
    }

    roomBoundary = roomBounds;
    name = inName;
    setParent(inParent);
    setFlag(GraphicsItemFlag::ItemIsSelectable, true);

    connect(this, SIGNAL(alarmSet()), inParent, SLOT(alarmSignal()));
}

void Room::redrawDoors()
{
    for (int i = 0; i < doors.length(); i++)
    {
        doors.at(i)->reDraw();
    }
}


void Room::setSecurityAlarmState(bool inState)
{
    securityAlarmState = inState;

    checkAlarmState(inState);
    if(inState)
    {
        dynamic_cast<Zone *>(parent())->lockAllDoors();
    }
    update();

}

bool Room::getSecurityAlarmState()
{
    return securityAlarmState;
}

void Room::setFireAlarmState(bool inState)
{
    fireAlarmState = inState;

    checkAlarmState(inState);
    update();
}

bool Room::getFireAlarmState()
{
    return fireAlarmState;
}

void Room::setSmokeAlarmState(bool inState)
{
    smokeAlarmState = inState;

    checkAlarmState(inState);
    update();
}

bool Room::getSmokeAlarmState()
{
    return smokeAlarmState;
}

void Room::setRoomNumber(int num)
{
    roomNum = num;
}

int Room::getRoomNumber()
{
    return roomNum;
}

void Room::clearAlarms()
{
    setFireAlarmState(false);
    setSmokeAlarmState(false);
    setSecurityAlarmState(false);
}


void Room::setSign(bool sign) {
    signs = sign;
}


QRectF Room::boundingRect() const
{
    return roomBoundary;
}

void Room::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(fireAlarmState)
    {
        painter->setBrush(QBrush(Qt::red, Qt::BrushStyle::SolidPattern));
    }
    else if(smokeAlarmState)
    {
        painter->setBrush(QBrush(Qt::red, Qt::BrushStyle::SolidPattern));
    }
    else if(securityAlarmState)
    {
        painter->setBrush(QBrush(Qt::yellow, Qt::BrushStyle::SolidPattern));
    }
    else {
        painter->setBrush(QBrush(Qt::gray, Qt::BrushStyle::SolidPattern));
    }
    painter->drawRect(roomBoundary);

    QFont font = painter->font() ;
    font.setPixelSize(60);
    painter->setFont(font);
    if (isSelected())
    {
        //lockDoors();
        painter->setBrush(QBrush(Qt::black, Qt::BrushStyle::CrossPattern));
        painter->drawRect(roomBoundary);
        painter->setPen(Qt::white);
    }
    else {
        painter->setPen(Qt::black);
        //unlockDoors();
    }


    painter->drawText(static_cast<int>(roomBoundary.x() + roomBoundary.width() / 2), static_cast<int>(roomBoundary.y() + roomBoundary.height() / 2), 300, 80, Qt::TextFlag::TextShowMnemonic, name);
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
void Room::setSigns(bool inVal)
{
    signs = inVal;
}

void Room::checkAlarmState(bool state)
{
    if (state == true)
        emit alarmSet();
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
