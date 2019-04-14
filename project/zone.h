#ifndef ZONE_H
#define ZONE_H


class Zone
{
public:
    Zone();
    void setCancelAlarm(bool alarm);
    void setConfirmAlarm(bool confirm);
    bool getCancelAlarm();
    bool getConfirmAlarm();
    int getAlertType();
    void setAlartType(int type);
};

#endif // ZONE_H
