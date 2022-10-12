#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include "../ArmyHierarchy/Army.h"

class Country
{
public:
    Country();
    ~Country();

    void setName(std::string);
    std::string getName();

    virtual void Attack(Country*) = 0;
    virtual void Retreat() = 0;
private:
    std::string name;
    Army* ARMY;
};

#endif