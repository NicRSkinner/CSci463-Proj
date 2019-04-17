#ifndef BUILDING_H
#define BUILDING_H

class Building
{
public:
    Building();
    void setPhoneNumber(int number);
    void setAddress(std::String string);
    void setOpen(bool status);
    int getPhoneNumber();
    std::String getAddress();
    bool getOpen();

};

#endif // BUILDING_H
