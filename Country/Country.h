#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include "../ArmyHierarchy/Army.h"
#include "Alliance.h"

class Army;
class Country
{
public:
    Country();
    ~Country();

    void setName(std::string);
    std::string getName();

    void addAlliance(Country*);
    void removeAlliance(Country*);

    void createArmy();

    void Attack();
    void Retreat();

    double getFunds();
    void addFunds(double);

private:
    Army *ARMY;
    Alliance *allianceList;
    std::string name;
    double funds;
};

#endif