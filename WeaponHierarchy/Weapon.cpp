#include "Weapon.h"

/**
 * @brief Weapons can be of three types, pistol rifle or explosive,
 *  each type has a long and short range varient.
 *  each weapon has a power factor that determines the damage that incurs.
 */
Weapon::Weapon(int damage) // creates weapon with power factor
{
    power = damage;
}

int Weapon::fire()
{
    return power;
}

Weapon::~Weapon(){}
