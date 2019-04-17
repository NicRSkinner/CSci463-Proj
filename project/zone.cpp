#include "zone.h"

bool emergencyAlarm, confirmCancel;
int alartType;

Zone::Zone()
{
    Zone();
}

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

