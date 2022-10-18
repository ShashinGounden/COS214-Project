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

    Person* clone();

    bool heal(Person*,int);
    int getID();

private:
    int id;
};

#endif