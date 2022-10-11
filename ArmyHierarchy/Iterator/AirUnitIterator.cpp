#include "AirUnitIterator.h"

/**
 * @brief Construct a new Air Unit Iterator:: Air Unit Iterator object
 *
 * @param list
 */
AirUnitIterator::AirUnitIterator(std::list<Person *> list) : ArmyIterator(list)
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
 * @brief
 *
 * @return Person*
 */
Person *AirUnitIterator::first()
{
    return unit.front();
}

/**
 * @brief
 *
 * @return Person*
 */
Person *AirUnitIterator::next()
{
    for (auto it = unit.begin(); it != unit.end(); it++)
    {
        if ((*it)->getID() == curr->getID())
        {
            it++;
            return (*it);
        }
    }
    std::cout << "Reached end of Unit!\n";
    std::cout << "Setting current to the front of the list\n";
    curr = unit.front();
    return curr;
}

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool AirUnitIterator::hasNext()
{
    if (curr == *unit.end())
    {
        return true;
    }
    else
        return false;
}

/**
 * @brief
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
    else{
        curr = first();
    }
}