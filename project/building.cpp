#include "building.h"

Building::Building()
{
    //Building();
    address = "yolo";
}

void Building::setPhoneNumber(int number) {
    phoneNumber = number;
}


void Building::setAddress(QString addres) {
    address = addres;
}


QString Building::getAddress() {
    return address;
}
