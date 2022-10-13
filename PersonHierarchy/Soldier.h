#ifndef SOLDIER_H
#define SOLDIER_H

#include "Person.h"

class Soldier : public Person
{
public:
    Soldier(int);
    ~Soldier();

    void Attack();
    void applyMedication();
    void Retreat();

    int getID();
private:
    int id;
};

#endif