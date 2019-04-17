#include "employee.h"

int SSN, phoneNumber;
std::String name, address, username, password;

Employee::Employee()
{
    Employee();
}

void setUsername(std::String user) {
    username = user;
}

void setPassword(std::String pass) {
    password = pass;
}

void setSSN(int number) {
    SSN = number
}

void setName(std::String user) {
    name = user;
}

void setAddress(std::String live) {
    address = live;
}

void setPhoneNumber(int number) {
    phoneNumber  = number;
}

int getSSN() {
    return SSN;
}

int getPhoneNumber() {
    return phoneNumber;
}

std::String getUsername() {
    return username;
}

std::String getPassword() {
    return password;
}

std::String getAddress() {
    return address;
}

std::String getName() {
    return name;
}
