#ifndef SOLDIER_H
#define SOLDIER_H

#include "Person.h"
#include "../WeaponHierarchy/Weapon.h"
#include "../WeaponHierarchy/WeaponFactory.h"
#include "../WeaponHierarchy/RifleFactory.h"
#include "../WeaponHierarchy/PistolFactory.h"

class Soldier : public Person
{
    protected:
    Weapon* weapon;
    
    public:
    Soldier(int, string);
    ~Soldier();
    Person* clone();
    void addWeapon(Weapon*) = 0;
};

#endif