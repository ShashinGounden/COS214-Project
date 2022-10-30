#ifndef ARTILLERY_H
#define ARTILLERY_H

#include "WMD.h"

class Artillery : public WMD
{
public:
    Artillery(Country*);
    ~Artillery();

    void wmd();
    void ArtilleryStrike();

    void Attack(Country*);
    void takeDamage(int);
};

#endif