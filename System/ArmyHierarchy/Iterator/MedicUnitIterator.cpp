#include "MedicUnitIterator.h"

/**
 * @brief Construct a new Medic Unit Iterator:: Medic Unit Iterator object
 * 
 * @param list 
 */
MedicUnitIterator::MedicUnitIterator(std::list<Person*> list) : ArmyIterator()
{
    unit = list;
    curr = unit.front();
}

/**
 * @brief Destroy the Medic Unit Iterator:: Medic Unit Iterator object
 * Will delete the Person objects in the Unit file destructor
 */
MedicUnitIterator::~MedicUnitIterator() {}

/**
 * @brief returns first Person*
 * 
 * @return Person* 
 */
Person *MedicUnitIterator::first()
{
    return unit.front();
}

/**
 * @brief returns pointer to next Person*
 * 
 * @return Person* 
 */
Person *MedicUnitIterator::next()
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
bool MedicUnitIterator::hasNext()
{
    if (curr == unit.back())
    {
        return false;
    }
    else
        return true;
}

/**
 * @brief returns Person* iterator is pointing to
 * 
 * @return Person* 
 */
Person *MedicUnitIterator::current()
{
    return curr;
}

/**
 * @brief moves Iterator one place forward 
 * 
 */
void MedicUnitIterator::increment()
{
    if (hasNext()){
        curr = next(); // current will be pointed to next person in unit
    }
}