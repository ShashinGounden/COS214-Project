#ifndef MEDICFACTORY_H
#define MEDICFACTORY_H

#include "PersonFactory.h"
#include "../Medic.h"

class MedicFactory : public PersonFactory
{
public:
    MedicFactory();
    ~MedicFactory();
    
    Person* createPerson(int, int, std::string);
};

#endif