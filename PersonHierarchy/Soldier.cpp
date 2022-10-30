#include "Soldier.h"

/**
 * @brief Construct a new Soldier:: Soldier object
 * Instantiating the weapon variable using the factory object
 * @param i - For the ID variable which is made from a rand() function
 */
Soldier::Soldier(int id, int i, std::string s) : Person(id, i, s) {}

Soldier::~Soldier(){}

/**
 * @brief for the prototype desgin pattern
 * 
 * @return Person* 
 */
Person *Soldier::clone()
{
    return new Soldier(getID(), getHealth(), getSkill());
}