#include "MedicUnit.h"
#include "../PersonHierarchy/PersonFactory/MedicFactory.h"

/**
 * @brief Construct a new Medic Unit:: Medic Unit object
 * Create a medic factory to then create Medic objects to pushback to
 * the unit object
 */
MedicUnit::MedicUnit()
{
    MedicFactory *factory = new MedicFactory();
    // make a loop to push back to unit with about 20 Person objects
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
