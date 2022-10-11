#include "GroundUnitIterator.h"

GroundUnitIterator::GroundUnitIterator(std::list<Person *> list) : ArmyIterator(list)
{
    unit = list;
    curr = unit.front();
}
/**
 * @brief Destroy the Ground Unit Iterator:: Ground Unit Iterator object
 * Going to delete all the person objects in the unit class
 */
GroundUnitIterator::~GroundUnitIterator() {}

Person *GroundUnitIterator::first()
{
    return unit.front();
}

Person *GroundUnitIterator::next()
{
    for (auto it = unit.begin(); it != unit.end(); it++)
    {
        if ((*it) == curr)
        { // NEED TO ADD What to compare to here!
            it++;
            return (*it);
        }
    }
    std::cout << "Reached end of Unit!\n";
    return nullptr;
}

bool GroundUnitIterator::hasNext()
{
    if (curr == *unit.end())
    {
        return false;
    }
    else
        return true;
}

Person *GroundUnitIterator::current()
{
    return curr;
}

void GroundUnitIterator::increment()
{
    if (hasNext())
    {
        curr = next(); // current will be pointed to next person in unit
    }
    else
    {
        curr = first(); // current can point back to the front of the list
    }
}