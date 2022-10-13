#ifndef MEDIC_H
#define MEDIC_H

#include "Person.h"

class Medic : public Person{
public:
    Medic(int);
    ~Medic();

    void Attack();
    void applyMedication();
    void Retreat();

    int getID();
private:
    int id;
};

#endif