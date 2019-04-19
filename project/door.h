#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QGraphicsObject>



class Door : public QGraphicsObject
{
    Q_OBJECT

public:
    Door(bool inState, QObject inObject); //Default const
    void setLockState(bool lock);
    bool getLockState();
private:
       bool lock;

};

#endif // DOOR_H
