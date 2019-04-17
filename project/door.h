#ifndef DOOR_H
#define DOOR_H

#include <QObject>



class Door : public QObject
{
    Q_OBJECT

public:
    virtual ~Door();
    Door(); //Default const
    void setLockState(bool lock);
    bool getLockState();
private:
       bool lock;

};

#endif // DOOR_H
