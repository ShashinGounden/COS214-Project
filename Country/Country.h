#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include "../ArmyHierarchy/Army.h"
#include "../Phase/Dominate.h"
#include "../Phase/Deter.h" 
#include "../Phase/Seize.h"
#include "Alliance.h"

class Country
{
public:
    Country(double); 
    Country(std::string,double);
    ~Country();

    void setName(std::string);
    std::string getName();

    void createArmy();

    void Attack(Country* c); 
    void takeDamage(int);
    void Retreat(); 
    bool surrender();

    double getFunds();
    void addFunds(double); 
  
    void joinAlliance(Alliance*); 
    void notify();

protected:
    Army *ARMY;
    std::string name;
    double funds;
    Phase* observedState; 
    Alliance* alliance;
};

#endif