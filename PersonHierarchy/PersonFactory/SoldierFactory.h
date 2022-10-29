#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "PersonFactory.h"
#include<string>

class SoldierFactory : public PersonFactory
{
public:
    SoldierFactory();
    ~SoldierFactory();

    Person* createPerson(int, int, string);
};

#endif