#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include "../ArmyHierarchy/Army.h"

class Army;
class Country
{
public:
    Country();
    ~Country();

    void setName(std::string);
    std::string getName();
    void createArmy();

    void Attack();
    void Retreat();

private:
    std::string name;
    Army *ARMY;
};

#endif