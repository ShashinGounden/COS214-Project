#include "Transport.h"

/**
 * @brief Construct a new transport object
 *  of type tank armoured truck or aircraft
 */

Transport::Transport() {}

/**
 * @brief Set vehicles health
 * 
 * @param d 
 */
void Transport::setHealth(int d)
{
    health = d;
}

/**
 * @brief Set vehicles defence
 * 
 * @param d 
 */
void Transport::setDefence(std::string d)
{
    defence = d;
}

/**
 * @brief return vehicles health
 * 
 * @return int 
 */
int Transport::getHealth()
{
    return health;
}

/**
 * @brief return vehicles defence
 * 
 * @return std::string 
 */
std::string Transport::getDefence()
{
    return defence;
}

Transport::~Transport() {}