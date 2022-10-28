#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include<string>
#include "../WeaponHierarchy/Weapon.h"

class Person
{
    protected:
    int hp;
    std::string skill; 

    public:
    Person(int, string);
    virtual ~Person();
    virtual Person* clone() = 0;
    int getHealth();
    string getSkill();
};

#endif