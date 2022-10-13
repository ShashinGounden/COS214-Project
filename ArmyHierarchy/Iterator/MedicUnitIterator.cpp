#include "MedicUnitIterator.h"

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

Person *MedicUnitIterator::first()
{
    return unit.front();
}

Person *MedicUnitIterator::next()
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
    std::cout<< "Setting current to the front of the list\n";
    curr = unit.front();
    return curr;
}

bool MedicUnitIterator::hasNext()
{
    if (curr->getID() == unit.back()->getID())
    {
        return false;
    }
    else
        return true;
}

Person *MedicUnitIterator::current()
{
    return curr;
}

void MedicUnitIterator::increment()
{
    if (hasNext()){
        curr = next(); // current will be pointed to next person in unit
    }
    else{
        curr = first(); // current can point back to the front of the list
    }
}