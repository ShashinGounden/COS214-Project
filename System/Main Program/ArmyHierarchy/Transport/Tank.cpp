#include "Tank.h"

/**
 * @brief Construct a new Tank:: Tank object
 * 
 */
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

/**
 * @brief Destroy the Tank:: Tank object
 * 
 */
Tank::~Tank() {}