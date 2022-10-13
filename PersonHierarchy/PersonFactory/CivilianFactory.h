#ifndef CIVILIANFACTORY_H
#define CIVILIANFACTORY_H

#include "PersonFactory.h"

class CivilianFactory : public PersonFactory
{
public:
    CivilianFactory();
    ~CivilianFactory();

    Person* createPerson(int);
};

#endif