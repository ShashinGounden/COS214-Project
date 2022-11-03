#include "Transport.h"
#include "Aircraft.h"

Aircraft::Aircraft() {}

/**
 * @brief sets the firepower of a weapon
 * 
 * @param d 
 */
void Aircraft::setPower(int d)
{
    damage = d;
}

Aircraft::~Aircraft() {}
