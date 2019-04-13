#include "room.h"

bool securityAlarm, fireAlarm, signs, controlRoom;

Room::Room(QWidget *parent) : QMainWindow(parent)
{

    //Default constructor can pass in values above
    Room();


}

void setSecurityAlarm(bool value) {
    securityAlarm = value;
}

void setAlarm(bool value) {
    fireAlarm = value;
}

void setDoor(Door::Door door) {
    //instanciate door
    //door = ;
}

void setZone(Zone::Zone zone) {
    //instanciate zone room is in
    //room = ;
}

void setSign(bool sign) {
    signs = sign;
}

void SetContrtolRoom(bool room) {
    controlRoom = room;
}

bool getSecurityAlarm() {
    return securityAlarm;
}

bool getFireAlarm(){
    return fireAlarm;
}
bool getDoor() {
    //return door
}
bool getZone() {
    //return zone
}
bool getControlRoom() {
    return controlRoom;
}
