#include "door.h"



Door::Door(bool inState, QObject inObject)
{
    setParent(&inObject);
    lock = inState;
}

void Door::setLockState(bool value) {
    lock = value;
}

bool Door::getLockState() {
    return lock;
}


