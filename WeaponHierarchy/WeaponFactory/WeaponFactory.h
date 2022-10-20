#ifndef WEAPONFACTORY_H
#define WEAPONFACTORY_H

#include"../Weapon.h"

class WeaponFactory
{
    public:
    WeaponFactory();
    Weapon* CreateShortRange() = 0;
    Weapon* CreateLongRange() = 0;
    ~WeaponFactory();
};

#endif