#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include "../ArmyHierarchy/Army.h"
class Country
{
public:
    Country(std::string);
    ~Country();

    std::string getName();

    void Attack(Country*);
private:
    std::string name;
    Army* ARMY;
};

#endif