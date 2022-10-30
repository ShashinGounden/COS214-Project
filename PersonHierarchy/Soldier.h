#ifndef SOLDIER_H
#define SOLDIER_H

#include "Person.h"
#include "../WeaponHierarchy/Weapon.h"
#include "../WeaponHierarchy/WeaponFactory.h"
#include "../WeaponHierarchy/RifleFactory.h"
#include "../WeaponHierarchy/PistolFactory.h"

class Soldier : public Person
{
public:
    Soldier(int, int, std::string);
    ~Soldier();
    Person *clone();
};

#endif