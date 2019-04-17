#ifndef DOOR_H
#define DOOR_H

#include <QObject>



class Door : public QObject
{
public:
    Door(bool inState); //Default const
    void setLockState(bool lock);
    bool getLockState();
private:
       bool lock;

};

#endif // DOOR_H
