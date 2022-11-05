#include "GroundUnitIterator.h"

/**
 * @brief Construct a new Ground Unit Iterator:: Ground Unit Iterator object
 * 
 * @param list 
 */
GroundUnitIterator::GroundUnitIterator(std::list<Person *> list) : ArmyIterator()
{
    unit = list;
    curr = unit.front();
}

/**
 * @brief Destroy the Ground Unit Iterator:: Ground Unit Iterator object
 * Going to delete all the person objects in the unit class
 */
GroundUnitIterator::~GroundUnitIterator() {}

/**
 * @brief returns pointer to first Person
 * 
 * @return Person* 
 */
Person *GroundUnitIterator::first()
{
    return unit.front();
}

/**
 * @brief returns pointer to the next Person
 * 
 * @return Person* 
 */
Person *GroundUnitIterator::next()
{
    for (auto it = unit.begin(); it != unit.end(); it++)
    {
        if ((*it) == curr)
        {
            it++;
            return (*it);
        }
    }
    return nullptr;
}

/**
 * @brief checks if Iterator is at the end of the unit
 * 
 * @return true 
 * @return false 
 */
bool GroundUnitIterator::hasNext()
{
    if (curr == unit.back())
    {
        return false;
    }
    else
        return true;
}

/**
 * @brief returns Person iterator is pointing 
 * 
 * @return Person* 
 */
Person *GroundUnitIterator::current()
{
    return curr;
}

/**
 * @brief moves iterator one place forward
 * 
 */
void GroundUnitIterator::increment()
{
    if (hasNext()){
        curr = next(); // current will be pointed to next person in unit
    }
}