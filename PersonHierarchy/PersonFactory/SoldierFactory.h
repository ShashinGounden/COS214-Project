#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "PersonFactory.h"

class SoldierFactory : public PersonFactory
{
public:
    SoldierFactory();
    ~SoldierFactory();

    Person* createPerson(int);
};

#endif