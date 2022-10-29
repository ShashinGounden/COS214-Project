#ifndef EXPLOSIVEFACTORY_H
#define EXPLOSIVEFACTORY_H

#include "WeaponFactory.h"
#include "Weapon.h"
#include "Bazooka.h"
#include "GasBomb.h"

class ExplosiveFactory : public WeaponFactory
{
public:
    ExplosiveFactory();
    Weapon *CreateShortRange();
    Weapon *CreateLongRange();
    ~ExplosiveFactory();
};

#endif
