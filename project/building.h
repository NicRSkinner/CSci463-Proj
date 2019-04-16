#ifndef BUILDING_H
#define BUILDING_H
#include "qstring.h"

class Building
{
public:
    Building();
    void setPhoneNumber(int number);
    void setAddress(QString string);
    void setOpen(bool status);
    int getPhoneNumber();
    QString getAddress();
    bool getOpen();

};

#endif // BUILDING_H
