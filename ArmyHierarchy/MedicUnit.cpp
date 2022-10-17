#include "MedicUnit.h"

/**
 * @brief Construct a new Medic Unit:: Medic Unit object
 * Create a medic factory to then create medic objects to pushback to
 * the unit object
 */
MedicUnit::MedicUnit() : Unit(){}

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
    delete factory;
}

void MedicUnit::populateUnit(){
    factory = new MedicFactory();
    for(int i = 0; i<20; i++){
        unit.push_back(factory->createPerson(rand()));
    }
}

ArmyIterator *MedicUnit::createIterator()
{
    return new MedicUnitIterator(unit);
}
