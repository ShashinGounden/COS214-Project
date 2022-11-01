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

    virtual std::string getName();

    void createArmy();

    virtual void Attack(Country* c); 
    virtual void takeDamage(int);
    virtual void Retreat(); 
    virtual bool surrender(Country*);

    virtual double getFunds();
    virtual void addFunds(double); 
  
    virtual void joinAlliance(Alliance*);
    virtual void notify(); 

    virtual Country* getCountry();

protected: 
    Country(){};
    Army *ARMY;
    std::string name;
    double funds;
    Phase* observedState; 
    Alliance* alliance;
};

#endif