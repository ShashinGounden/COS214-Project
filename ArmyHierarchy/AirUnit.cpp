#include "AirUnit.h"

/**
 * @brief Construct a new Ground Unit:: Ground Unit object
 * Create a soldier factory to then create soldier objects to pushback to
 * the unit object
 */
AirUnit::AirUnit() : Unit(){}

AirUnit::~AirUnit(){
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

void AirUnit::populateUnit(int numOfPilots){
    factory = new SoldierFactory();
    for(int i = 0; i<numOfPilots; i++){
        unit.push_back(factory->createPerson(rand()));
    }
}

/**
 * @brief returns iterator object
 * 
 * @return ArmyIterator* 
 */
ArmyIterator *AirUnit::createIterator(){
    return new AirUnitIterator(unit);
}
