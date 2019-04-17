#include "door.h"



Door::Door(bool inState)
{
    lock = inState;
}


void Door::setLockState(bool value) {
    lock = value;
}

bool Door::getLockState() {
    return lock;
}
