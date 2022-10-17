#include "GroundUnit.h"

/**
 * @brief Construct a new Ground Unit:: Ground Unit object
 * Create a soldier factory to then create soldier objects to pushback to
 * the unit object
 */
GroundUnit::GroundUnit() : Unit(){}

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
    delete factory;
}

void GroundUnit::populateUnit(){
    factory = new SoldierFactory();
    for(int i = 0; i<20; i++){
        unit.push_back(factory->createPerson(rand()));
    }
}

ArmyIterator *GroundUnit::createIterator()
{
    return new GroundUnitIterator(unit);
}
