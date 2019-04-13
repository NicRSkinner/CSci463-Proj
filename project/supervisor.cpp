#include "supervisor.h"

bool cancelAlarm, confirmAlarm;

Supervisor::Supervisor()
{
    Supervisor();
}

void setCancelAlarm(bool alarm) {
    cancelAlarm = alarm;
}

void setConfirmAlarm(bool alarm) {
    confirmAlarm = alarm;
}

bool getCancelAlarm() {
    return cancelAlarm;
}

bool getConfirmAlarm() {
    return confirmAlarm;
}

