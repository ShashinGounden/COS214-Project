#ifndef ARMY_H
#define ARMY_H

#include "MedicUnit.h"
#include "GroundUnit.h"
#include "AirUnit.h"

class Army{
public:
    Army(int,int,int);
    ~Army();

    // For iterator
    void populateUnit(int,int,int);

    void Attack();
    void Advance();
    void Retreat();
    void Surrender();

    // For Observer
    void update();

private:
    MedicUnit *medicUnit;
    GroundUnit *groundUnit;
    AirUnit *airUnit;
};

#endif