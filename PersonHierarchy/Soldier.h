#ifndef SOLDIER_H
#define SOLDIER_H

#include "Person.h"
#include "../WeaponHierarchy/Weapon.h"

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
    Weapon* weapon;

private:
    int id;
};

#endif