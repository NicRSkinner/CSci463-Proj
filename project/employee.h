#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
public:
    Employee();
    void setUsername(std::String user);

    void setPassword(std::String pass);

    void setSSN(int number);

    void setName(std::String user);

    void setAddress(std::String live);

    void setPhoneNumber(int number);

    int getSSN();

    int getPhoneNumber();

    std::String getUsername();

    std::String getPassword();

    std::String getAddress();

    std::String getName();
};

#endif // EMPLOYEE_H
