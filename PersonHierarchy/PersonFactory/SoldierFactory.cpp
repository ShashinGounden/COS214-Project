#include "SoldierFactory.h"
#include "../Soldier.h"

SoldierFactory::SoldierFactory(){}

SoldierFactory::~SoldierFactory(){}

Person* SoldierFactory::createPerson(){
    return new Soldier();
}