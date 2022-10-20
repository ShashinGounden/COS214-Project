#include "Transport.h"

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