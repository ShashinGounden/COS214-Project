#ifndef MEDICFACTORY_H
#define MEDICFACTORY_H

#include "PersonFactory.h"

class MedicFactory : public PersonFactory
{
public:
    MedicFactory();
    ~MedicFactory();
    
    Person* createPerson(int);
};

#endif