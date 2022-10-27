#include "Soldier.h"

/**
 * @brief Construct a new Soldier:: Soldier object
 * Instantiating the weapon variable using the factory object
 * @param i - For the ID variable which is made from a rand() function
 */
Soldier::Soldier(int i) : Person(i)
{
    factory = new RifleFactory();
    weapon = factory->CreateLongRange();
    id = i;
}

Soldier::~Soldier()
{
    if(weapon != NULL)
    {
        delete weapon;
        weapon = NULL;
    }
    std::cout << "ID: " << id << " Deleted\n";
}

void Soldier::Attack()
{
    if (id % 47 == 0)
    {
        std::cout << "ATTACK!\n";
    }
}

void Soldier::applyMedication() {}

void Soldier::Retreat()
{
    if (id % 51 == 0)
    {
        std::cout << "RETREAT!\n";
    }
}

Person *Soldier::clone()
{
    return new Soldier(getID());
}

/**
 * @brief Not implementing - Only for Medic
 *
 * @return true
 * @return false
 */
bool Soldier::heal(Person *, int)
{
    return false;
}

int Soldier::getID()
{
    return id;
}