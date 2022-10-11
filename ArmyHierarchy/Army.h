#ifndef ARMY_H
#define ARMY_H

#include "MedicUnit.h"
#include "GroundUnit.h"
#include "AirUnit.h"

class Army
{
public:
    Army();
    ~Army();

    // For iterator
    void createMedicUnit();
    void createGroundUnit();
    void createAirUnit();

    // For Observer
    void update();

private:
    MedicUnit *medicUnit;
    GroundUnit *groundUnit;
    AirUnit *airUnit;
};

#endif