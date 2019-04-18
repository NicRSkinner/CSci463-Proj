#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <QObject>

class Supervisor : public QObject
{
    Q_OBJECT
private:
    bool cancelAlarm, confirmAlarm;
public:
    Supervisor();
    void setCancelAlarm(bool alarm);

    void setConfirmAlarm(bool alarm);

    bool getCancelAlarm();

    bool getConfirmAlarm();
};

#endif // SUPERVISOR_H
