#include "room.h"

//bool securityAlarm, fireAlarm, signs;


Room::Room(QGraphicsRectItem *roomRectangle)
{

    // TODO : FINISH CONSTRUCTOR
    //    setSecurityAlarm(inSecAlarm);
    //    setAlarm(inFireAlarm);
    //    setZone(inZone);

    securityAlarm = false;
    graphicsRoomRectangle = roomRectangle;
}


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

/*
void Room::setZone(Zone zone) {
    //instanciate zone room is in
    //room = ;
    Room::zone = &zone;
}
*/
void Room::setSign(bool sign) {
    signs = sign;
}

bool Room::getSecurityAlarmState() {
    return securityAlarm;
}

bool Room::getFireAlarmState(){
    return fireAlarm;
}

QGraphicsRectItem* Room::getRoomGraphicsItem()
{
    return graphicsRoomRectangle;
}


/*

void Room::addDoor(Door door) {
    //instanciate door
    //door = ;
    Room::doors.append(door);
}

QList<Door> Room::getDoors() {
    //return door
    return doors;
}

void Room::getZone() {
    //return zone
    return Room::zone;
}
*/
