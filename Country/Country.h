#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include "../ArmyHierarchy/Army.h"
#include "../Phase/Dominate.h"
#include "../Phase/Deter.h"
#include "../Phase/Seize.h"

class Alliance;

class Country
{
public: 
    Country(std::string,double);
    virtual ~Country();

    std::string getName();

    void createArmy();

    virtual void Attack(Country* c); 
    virtual void takeDamage(int);
    void Retreat(); 
    bool surrender();

    double getFunds();
    void addFunds(double); 
  
    void joinAlliance(Alliance*);
    void notify();

protected: 
    Country(){};
    Army *ARMY;
    std::string name;
    double funds;
    Phase* observedState; 
    Alliance* alliance;
};

#endif