#include "employee.h"

extern int SSN, phoneNumber;
extern QString name, address, username, password;

Employee::Employee()
{
    Employee();
}

void setUsername(QString user) {
    username = user;
}

void setPassword(QString pass) {
    password = pass;
}

void setSSN(int number) {
    SSN = number;
}

void setName(QString user) {
    name = user;
}

void setAddress(QString live) {
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

QString getUsername() {
    return username;
}

QString getPassword() {
    return password;
}

QString getAddress() {
    return address;
}

QString getName() {
    return name;
}
