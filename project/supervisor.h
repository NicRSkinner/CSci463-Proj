#ifndef SUPERVISOR_H
#define SUPERVISOR_H


class Supervisor
{
public:
    Supervisor();
    void setCancelAlarm(bool alarm);

    void setConfirmAlarm(bool alarm);

    bool getCancelAlarm();

    bool getConfirmAlarm();
};

#endif // SUPERVISOR_H
