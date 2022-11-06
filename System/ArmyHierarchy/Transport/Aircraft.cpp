#include "Transport.h"
#include "Aircraft.h"

/**
 * @brief Construct a new Aircraft:: Aircraft object
 * 
 */
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

/**
 * @brief Destroy the Aircraft:: Aircraft object
 * 
 */
Aircraft::~Aircraft() {}
