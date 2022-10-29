#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "../WeaponHierarchy/Weapon.h"

class Person
{
    protected:
    int hp;
    std::string skill; 
    int ID;
    Weapon *weapon;

    public:
    Person(int, int, std::string);
    virtual ~Person();
    virtual Person* clone() = 0;
    int getHealth();
    std::string getSkill();
    void addWeapon(Weapon*);
    Weapon* getWeapon();
    int heal();
    int getID();
};

#endif