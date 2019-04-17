#include "door.h"


Door::Door()
{
    lock = false;
}
Door::~Door()
{
    lock = false;
}

void Door::setLockState(bool value) {
    lock = value;
}

bool Door::getLockState() {
    return lock;
}
