#include "SoldierFactory.h"
#include "../Soldier.h"

SoldierFactory::SoldierFactory(){}

SoldierFactory::~SoldierFactory(){}

Person* SoldierFactory::createPerson(int id, int i, string s)
{
    return new Soldier(id, i, s);
}