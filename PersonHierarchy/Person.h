#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "../WeaponHierarchy/Weapon.h"

class Person
{
public:
    Person(int);
    virtual ~Person();

    virtual void Attack() = 0;
    virtual void Retreat() = 0;

    virtual int getID() = 0;
    virtual Person* clone() = 0;

    virtual bool heal(Person*, int) = 0;
    void addHealth(int);
    int getHealth();
    int takeDamage(int); 
    int getPower();

protected:
    int hp;
    Weapon* weapon;
    // std::string skill; // dunno what to do with skill for now
};

#endif