#include "Transport.h"

/**
 * @brief Construct a new transport object
 *  of type tank armoured truck or aircraft
 */

Transport:: Transport(){}

void Transport:: setHealth(int d)
{
    health = d;
}

void Transport:: setDefence(string d)
{
    defence = d;
}

int Transport:: getHealth()
{
    return health;
}

string Transport:: getDefence()
{
    return defence;
}

Transport:: ~Transport(){}