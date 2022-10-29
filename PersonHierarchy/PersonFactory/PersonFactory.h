#ifndef PERSONFACTORY_H
#define PERSONFACTORY_H

#include "../Person.h"
#include<string>

class PersonFactory
{
public:
    PersonFactory();
    virtual ~PersonFactory();

    virtual Person* createPerson(int, int, string) = 0;
};

#endif