#ifndef PISTOLFACTORY_H
#define PISTOLFACTORY_H

#include "WeaponFactory.h"
#include "../Weapon.h"

class PistolFactory : public WeaponFactory
{
    public:
    PistolFactory();
    Weapon* CreateShortRange();
    Weapon* CreateLongRange();
    ~PistolFactory();
};

#endif