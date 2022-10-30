#include "Person.h"
#include <string>
#include "../WeaponHierarchy/Weapon.h"

/**
 * @brief Construct a new Person:: Person object
 *
 * @param i
 */
Person::Person(int id, int i, std::string s)
{
    ID = id;
    skill = s;
    hp = 100;
}

/**
 * @brief Destroy the Person:: Person object
 * if the weapon object was instantiated too then it gets deleted too
 * 
 */
Person::~Person()
{
    if (weapon != NULL)
    {
        delete weapon;
        weapon = NULL;
    }
}

int Person::getHealth()
{
    return hp;
}

std::string Person::getSkill()
{
    return skill;
}

void Person::addWeapon(Weapon *W)
{
    weapon = W;
}

Weapon* Person::getWeapon(){
    return weapon;
}

/**
 * @brief
 *
 * Returns value of medics healing
 *
 * @return int
 */
int Person::heal()
{
    return 20;
}

int Person::getID()
{
    return ID;
}
