#ifndef WMD_H
#define WMD_H

#include "Country.h"

class WMD : public Country
{
public: 
  
    WMD(Country*); 
    virtual ~WMD();

    virtual void wmd() = 0; 
    virtual void Attack(Country*){}; 
    virtual void takeDamage(int){}; 
    bool surrender(Country*); 
    void Retreat();
    std::string getName();
    void addFunds(double); 
    double getFunds(); 
    void joinAlliance(Alliance*); 
    void notify();  
    int getNumOfSoldiers();
    Country* getCountry();

protected:
    Country* owner;
};

#endif