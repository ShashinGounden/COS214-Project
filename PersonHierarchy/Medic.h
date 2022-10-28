#ifndef MEDIC_H
#define MEDIC_H

#include "Person.h"

class Medic : public Person
{
    public:
    Medic(int, string);
    ~Medic();
    Person* clone();
    int Heal();
};

#endif