#include "building.h"

int phoneNumber;
bool open;
QString address;


Building::Building()
{
    Building();
}

void setPhoneNumber(int number) {
    phoneNumber = number;
}

void setOpen(bool status) {
    open = status;
}

void setAddress(QString addres) {
    address = addres;
}

int getPhoneNumber() {
    return phoneNumber;
}

bool getOpen(){
    return open;
}

QString getAddress() {
    return address;
}
