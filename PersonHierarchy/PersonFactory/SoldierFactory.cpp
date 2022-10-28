#include "SoldierFactory.h"
#include "../Soldier.h"

SoldierFactory::SoldierFactory(){}

SoldierFactory::~SoldierFactory(){}

Person* SoldierFactory::createPerson(int i, string s)
{
    return new Soldier(i, s);
}