#include "Medic.h"

/**
 * @brief Construct a new Medic:: Medic object
 * 
 * @param id 
 * @param i 
 * @param s 
 */
Medic::Medic(int id, int i, std::string s) : Person(id, i, s) {}

Medic::~Medic() {}

/**
 * @brief for the prototype design pattern
 * 
 * @return Person* 
 */
Person *Medic::clone()
{
    return new Medic(getID(), getHealth(), getSkill());
}
