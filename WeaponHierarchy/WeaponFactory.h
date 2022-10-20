#ifndef WEAPONFACTORY_H
#define WEAPONFACTORY_H

#include"Weapon.h"

class WeaponFactory
{
    public:
    WeaponFactory();
    virtual Weapon* CreateShortRange() = 0;
    virtual Weapon* CreateLongRange() = 0;
    ~WeaponFactory();
};

#endif
