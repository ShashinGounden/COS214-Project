#include "Tank.h"

Tank::Tank() {}

/**
 * @brief sets Tanks secondary weapon
 * 
 * @param d 
 */
void Tank::setSecondary(std::string d)
{
    secondaryWeapon = d;
}

Tank::~Tank() {}