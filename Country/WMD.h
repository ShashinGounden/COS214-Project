#ifndef WMD_H
#define WMD_H

#include "Country.h"

class WMD : public Country
{
public: 
  
    WMD(Country*); 
    WMD();
    virtual ~WMD();

    virtual void wmd() = 0; 
    virtual void Attack(Country*){}; 
    virtual void takeDamage(int){};

protected:
    Country* owner;
};

#endif