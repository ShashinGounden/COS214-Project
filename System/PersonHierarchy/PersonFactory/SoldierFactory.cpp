#include "SoldierFactory.h"

SoldierFactory::SoldierFactory(){}

SoldierFactory::~SoldierFactory(){}

Person* SoldierFactory::createPerson(int id, int i, std::string s)
{
    return new Soldier(id, i, s);
}