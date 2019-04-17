#include "supervisor.h"



Supervisor::Supervisor()
{
    cancelAlarm = false;
}

void Supervisor::setCancelAlarm(bool alarm) {
    cancelAlarm = alarm;
}

void Supervisor::setConfirmAlarm(bool alarm) {
    confirmAlarm = alarm;
}


bool Supervisor::getCancelAlarm() {
    return cancelAlarm;
}

bool Supervisor::getConfirmAlarm() {
    return confirmAlarm;
}

