#include "MedicUnit.h"

/**
 * @brief Construct a new Medic Unit:: Medic Unit object
 * Create a medic factory to then create medic objects to pushback to
 * the unit object
 */
MedicUnit::MedicUnit() : Unit()
{

    PersonFactory *factory = new MedicFactory();
    // make a loop to push back to unit with about 20 Person objects
    for(int i = 0; i<20; i++){
        unit.push_back(factory->createPerson(rand()));
    }
    delete factory;
}

MedicUnit::~MedicUnit()
{
    /**
     * @brief - Delete all person objects in unit list object
     *
     */
    for (auto it = unit.begin(); it != unit.end(); it++)
    {
        delete (*it);
    }
}

ArmyIterator *MedicUnit::createIterator()
{
    return new MedicUnitIterator(unit);
}
