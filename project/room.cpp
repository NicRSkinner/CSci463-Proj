#include "room.h"

extern bool securityAlarm, fireAlarm, signs, controlRoom;

/*
Room()
{

    // TODO : FINISH CONSTRUCTOR
    //    setSecurityAlarm(inSecAlarm);
    //    setAlarm(inFireAlarm);
    //    setZone(inZone);



}
*/
void setSecurityAlarm(bool value) {
    securityAlarm = value;
}

void setAlarm(bool value) {
    fireAlarm = value;
}

void setDoor(Door door) {
    //instanciate door
    //door = ;
}

void setZone(Zone zone) {
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
