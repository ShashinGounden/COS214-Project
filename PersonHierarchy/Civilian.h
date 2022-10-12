#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "Person.h"

class Civilian : public Person
{
public:
    Civilian();

    void Attack(Country*);
    void applyMedication();
    void Retreat();

private:
    int id;
};

#endif