#include "GroundUnit.h"

/**
 * @brief Construct a new Ground Unit:: Ground Unit object
 * Create a soldier factory to then create soldier objects to pushback to
 * the unit object
 */
GroundUnit::GroundUnit()
{
    PersonFactory *factory = new SoldierFactory();
    // make a loop to push back to unit with about 20 Person objects
    for(int i = 0; i<20; i++){
        unit.push_back(factory->createPerson());
    }
    delete factory;
}

GroundUnit::~GroundUnit()
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

ArmyIterator *GroundUnit::createIterator()
{
    return new GroundUnitIterator(unit);
}
