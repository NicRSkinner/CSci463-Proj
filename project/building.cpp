#include "building.h"

int phoneNumber;
bool open;
std::String address;


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

void setAddress(std::String addres) {
    address = addres;
}

int getPhoneNumber() {
    return phoneNumber;
}

bool getOpen(){
    return open;
}

std::String getAddress() {
    return address;
}
