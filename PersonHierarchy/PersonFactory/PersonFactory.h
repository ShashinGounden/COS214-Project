#ifndef PERSONFACTORY_H
#define PERSONFACTORY_H

#include "../Person.h"

class PersonFactory
{
public:
    PersonFactory();
    virtual ~PersonFactory();

    virtual Person* createPerson(int, string) = 0;
};

#endif