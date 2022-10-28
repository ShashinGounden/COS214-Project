#include "Person.h"
#include<string>
#include "../WeaponHierarchy/Weapon.h"

/**
 * @brief Construct a new Person:: Person object
 * 
 * @param i 
 */

Person::Person(int i, string s)
{
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

