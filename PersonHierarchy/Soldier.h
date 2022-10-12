#ifndef SOLDIER_H
#define SOLDIER_H

#include "Person.h"

class Soldier : public Person
{
public:
    Soldier();

    void Attack(Country*);
    void applyMedication();
    void Retreat();

private:
    int id;
};

#endif