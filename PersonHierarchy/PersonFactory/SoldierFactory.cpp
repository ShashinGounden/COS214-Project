#include "SoldierFactory.h"
#include "../Soldier.h"

SoldierFactory::SoldierFactory(){}

SoldierFactory::~SoldierFactory(){}

Person* SoldierFactory::createPerson(int i){
    return new Soldier(i);
}