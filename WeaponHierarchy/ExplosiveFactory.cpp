#include "ExplosiveFactory.h"

ExplosiveFactory::ExplosiveFactory() : WeaponFactory() {}

Weapon *ExplosiveFactory::CreateLongRange()
{
    Weapon *w = new Bazooka(100);
    return w;
}

Weapon *ExplosiveFactory::CreateShortRange()
{
    Weapon *w = new GasBomb(100);
    return w;
}

ExplosiveFactory::~ExplosiveFactory() {}
