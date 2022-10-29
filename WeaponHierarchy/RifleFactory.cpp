#include "RifleFactory.h"
#include "Weapon.h"
#include "M1917Enfield.h"
#include "M1Garand.h"

RifleFactory::RifleFactory() : WeaponFactory() {}

Weapon *RifleFactory::CreateLongRange()
{
    Weapon *w = new M1917Enfield(60);
    return w;
}

Weapon *RifleFactory::CreateShortRange()
{
    Weapon *w = new M1Garand(60);
    return w;
}

RifleFactory::~RifleFactory() {}
