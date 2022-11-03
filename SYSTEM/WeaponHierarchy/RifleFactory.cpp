#include "RifleFactory.h"
#include "Weapon.h"
#include "M1917Enfield.h"
#include "M1Garand.h"

RifleFactory::RifleFactory() : WeaponFactory() {}

/**
 * @brief Creating a M1917Enfield object
 * 
 * @return Weapon* 
 */
Weapon *RifleFactory::CreateLongRange()
{
    Weapon *w = new M1917Enfield(60);
    return w;
}

/**
 * @brief Creating a M1Garand object
 * 
 * @return Weapon* 
 */
Weapon *RifleFactory::CreateShortRange()
{
    Weapon *w = new M1Garand(60);
    return w;
}

RifleFactory::~RifleFactory() {}
