#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "Person.h"

class Civilian : public Person
{
public:
    Civilian(int);
    ~Civilian();

    void Attack();
    void applyMedication();
    void Retreat();

    int getID();
private:
    int id;
};

#endif