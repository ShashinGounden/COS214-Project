#include "Weapon.h"


Weapon:: Weapon(int damage) // creates weapon with power factor
{
    power = damage;
}

int Weapon:: fire()
{
    return power;
}

Weapon:: ~Weapon(){}
