#ifndef RIFLEFACTORY_H
#define RIFLEFACTORY_H

#include "WeaponFactory.h"
#include "../Weapon.h"

class RifleFactory : public WeaponFactory
{
    public:
    RifleFactory();
    Weapon* CreateShortRange();
    Weapon* CreateLongRange();
    ~RifleFactory();
};

#endif