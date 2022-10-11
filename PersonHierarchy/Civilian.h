#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "Person.h"

class Civilian : public Person
{
public:
    Civilian();

    void attack();
    void applyMedication();
    void retreat();

private:
    int id;
};

#endif