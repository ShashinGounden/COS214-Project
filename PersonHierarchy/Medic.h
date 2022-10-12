#ifndef MEDIC_H
#define MEDIC_H

#include "Person.h"

class Medic : public Person
{
public:
    Medic();

    void Attack(Country*);
    void applyMedication();
    void Retreat();

private:
    int id;
};

#endif