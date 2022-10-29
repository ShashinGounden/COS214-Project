#include "Person.h"
#include<string>
#include "../WeaponHierarchy/Weapon.h"

/**
 * @brief Construct a new Person:: Person object
 * 
 * @param i 
 */

Person::Person(int id, int i, string s)
{
    ID = id;
    skill = s;
    hp = 100;
}

Person::~Person(){}

int Person::getHealth()
{
    return hp;
}

string Person:: getSkill()
{
    return skill;
}

int Person:: getID()
{
    return ID;
}

