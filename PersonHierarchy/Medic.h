#ifndef MEDIC_H
#define MEDIC_H

#include "Person.h"

class Medic : public Person
{
public:
    Medic();

    void attack();
    void applyMedication();
    void retreat();

private:
    int id;
};

#endif