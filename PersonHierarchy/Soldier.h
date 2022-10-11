#ifndef SOLDIER_H
#define SOLDIER_H

#include "Person.h"

class Soldier : public Person
{
public:
    Soldier();

    void attack();
    void applyMedication();
    void retreat();

private:
    int id;
};

#endif