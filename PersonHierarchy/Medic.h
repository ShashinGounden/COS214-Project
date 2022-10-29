#ifndef MEDIC_H
#define MEDIC_H

#include "Person.h"
#include<string>

class Medic : public Person
{
    public:
    Medic(int, int, string);
    ~Medic();
    Person* clone(int, int, string);
    int Heal();
};

#endif