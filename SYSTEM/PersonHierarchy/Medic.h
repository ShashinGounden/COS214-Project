#ifndef MEDIC_H
#define MEDIC_H

#include "Person.h"

class Medic : public Person
{
public:
    Medic(int, int, std::string);
    ~Medic();
    Person *clone();
};

#endif