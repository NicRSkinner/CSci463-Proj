#ifndef ZONE_H
#define ZONE_H

#include <QObject>

class Zone : public QObject
{
    Q_OBJECT
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
