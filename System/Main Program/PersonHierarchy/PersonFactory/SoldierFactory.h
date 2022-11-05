#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "PersonFactory.h"
#include "../Soldier.h"

class SoldierFactory : public PersonFactory
{
public:
    SoldierFactory();
    ~SoldierFactory();

    Person* createPerson(int, int, std::string);
};

#endif