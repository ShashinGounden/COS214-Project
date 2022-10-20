#include "Weapon.h"

class Weapon
{
    Weapon:: Weapon(int damage) // creates weapon with power factor
    {
        power = damage;
    }

    int Weapon:: fire()
    {
        return this.power;
    }

    Weapon:: ~Weapon(){}
}