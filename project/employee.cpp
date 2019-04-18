#include "employee.h"

extern int SSN, phoneNumber;
extern QString name, address, username, password;

Employee::Employee()
{
    SSN = 0;
    phoneNumber = 0;
}

void Employee::setUsername(QString user) {
    username = user;
}

void Employee::setPassword(QString pass) {
    password = pass;
}

void Employee::setSSN(int number) {
    SSN = number;
}

void Employee::setName(QString user) {
    name = user;
}

void Employee::setAddress(QString live) {
    address = live;
}

void Employee::setPhoneNumber(int number) {
    phoneNumber  = number;
}

int Employee::getSSN() {
    return SSN;
}

int Employee::getPhoneNumber() {
    return phoneNumber;
}

QString Employee::getUsername() {
    return username;
}

QString Employee::getPassword() {
    return password;
}

QString Employee::getAddress() {
    return address;
}

QString Employee::getName() {
    return name;
}
