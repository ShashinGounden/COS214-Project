#ifndef ARMY_H
#define ARMY_H

#include "MedicUnit.h"
#include "GroundUnit.h"
#include "AirUnit.h"

class Army{
public:
    Army();
    ~Army();

    // For iterator
    void populateUnit();

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