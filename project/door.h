#ifndef DOOR_H
#define DOOR_H

#include <QObject>



class Door : public QObject
{
public:
    //Door(); //Default const
    void setLock(bool lock);
    bool getLock();

};

#endif // DOOR_H
