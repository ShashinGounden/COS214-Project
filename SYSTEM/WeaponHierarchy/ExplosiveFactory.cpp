#include "ExplosiveFactory.h"

ExplosiveFactory::ExplosiveFactory() : WeaponFactory() {}

/**
 * @brief to create a Bazooka object
 * 
 * @return Weapon* 
 */
Weapon *ExplosiveFactory::CreateLongRange()
{
    Weapon *w = new Bazooka(100);
    return w;
}

/**
 * @brief to create a GasBomb object
 * 
 * @return Weapon* 
 */
Weapon *ExplosiveFactory::CreateShortRange()
{
    Weapon *w = new GasBomb(100);
    return w;
}

ExplosiveFactory::~ExplosiveFactory() {}
