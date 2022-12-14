#include "PistolFactory.h"
#include "Weapon.h"
#include "Cal45short.h"
#include "Colt12B.h"

PistolFactory::PistolFactory() : WeaponFactory() {}

/**
 * @brief creating a Colt12B object
 * 
 * @return Weapon* 
 */
Weapon *PistolFactory::CreateLongRange()
{
    Weapon *w = new Colt12B(25);
    return w;
}

/**
 * @brief creating a Cal45short object
 * 
 * @return Weapon* 
 */
Weapon *PistolFactory::CreateShortRange()
{
    Weapon *w = new Cal45short(25);
    return w;
}

PistolFactory::~PistolFactory() {}
