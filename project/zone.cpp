#include "zone.h"

extern bool emergencyAlarm, confirmCancel;
extern int alartType;

void setCancelAlarm(bool value) {
    emergencyAlarm = value;
}

void setConfirmAlarm(bool confirm) {
    confirmCancel = confirm;
}

void setAlartType(int type) {
    alartType = type;
}

bool getEmergencyAlarm() {
    return emergencyAlarm;
}

bool getAlarmType() {
    return alartType;
}

