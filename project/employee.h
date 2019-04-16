#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "qstring.h"

class Employee
{
private:
    int SSN, phoneNumber;
    QString name, address, username, password;
public:
    Employee();
    void setUsername(QString user);

    void setPassword(QString pass);

    void setSSN(int number);

    void setName(QString user);

    void setAddress(QString live);

    void setPhoneNumber(int number);

    int getSSN();

    int getPhoneNumber();

    QString getUsername();

    QString getPassword();

    QString getAddress();

    QString getName();
};

#endif // EMPLOYEE_H
