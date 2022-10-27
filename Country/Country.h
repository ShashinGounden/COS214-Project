#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include "../ArmyHierarchy/Army.h"
#include "../Phase/Phase.h"

class Country
{
public:
    Country(double);
    ~Country();

    void setName(std::string);
    std::string getName();

    void createArmy();

    void Attack();
    void Retreat();

    double getFunds();
    void addFunds(double);

    Phase* update();

protected:
    Army *ARMY;
    std::string name;
    double funds;
    Phase* observedState;
};

#endif