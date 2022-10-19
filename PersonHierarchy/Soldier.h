#ifndef SOLDIER_H
#define SOLDIER_H

#include "Person.h"
#include "../WeaponHierarchy/Weapon.h"
#include "../WeaponHierarchy/WeaponFactory/WeaponFactory.h"

class Soldier : public Person
{
public:
    Soldier(int);
    ~Soldier();

    void Attack();
    void applyMedication();
    void Retreat();

    bool heal(Person*,int);
    void changeWeapon(Weapon*);

    Person* clone();

    int getID();

protected:
    WeaponFactory* factory;

private:
    Weapon* weapon;
    int id;
};

#endif