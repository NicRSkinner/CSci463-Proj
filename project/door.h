#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QGraphicsItem>



class Door : public QObject, public QGraphicsItem
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
