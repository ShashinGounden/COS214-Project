#include "Weapon.h"

class Weapon
{
    Weapon:: Weapon(int damage)
    {
        power = damage;
    }

    int Weapon:: fire()
    {
        return this.power;
    }

    Weapon:: ~Weapon(){}
}