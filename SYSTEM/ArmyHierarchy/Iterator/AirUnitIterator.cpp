#include "AirUnitIterator.h"

/**
 * @brief Construct a new Air Unit Iterator:: Air Unit Iterator object
 *
 * @param list
 */
AirUnitIterator::AirUnitIterator(std::list<Person *> list) : ArmyIterator()
{
    unit = list;
    curr = unit.front();
}
/**
 * @brief Destroy the Air Unit Iterator:: Air Unit Iterator object
 * Going to delete all person objects in the AirUnit class
 */
AirUnitIterator::~AirUnitIterator() {}

/**
 * @brief returns fisrt Person* in Unit
 *
 * @return Person*
 */
Person *AirUnitIterator::first()
{
    return unit.front();
}

/**
 * @brief returns pointer to next Person
 *
 * @return Person*
 */
Person *AirUnitIterator::next()
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
 * @brief checks if Iterator has reached end of Unit
 *
 * @return true
 * @return false
 */
bool AirUnitIterator::hasNext()
{
    if (curr == unit.back())
    {
        return false;
    }
    else
        return true;
}

/**
 * @brief returns current Person*
 *
 * @return Person*
 */
Person *AirUnitIterator::current()
{
    return curr;
}

/**
 * @brief
 * This it to change current to next
 */
void AirUnitIterator::increment()
{
    if (hasNext()){
        curr = next();
    }
}