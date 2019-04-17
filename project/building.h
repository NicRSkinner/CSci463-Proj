#ifndef BUILDING_H
#define BUILDING_H
#include <QString>

class Building
{
public:
    Building();
    void setPhoneNumber(int number);
    void setAddress(QString string);
    int getPhoneNumber();
    QString getAddress();
    bool getOpen();

private:
    int phoneNumber;
    QString address;

};

#endif // BUILDING_H
