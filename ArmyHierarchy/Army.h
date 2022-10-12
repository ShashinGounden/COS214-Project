#ifndef ARMY_H
#define ARMY_H

#include "../Country/Country.h"
#include "MedicUnit.h"
#include "GroundUnit.h"
#include "AirUnit.h"

class Army : public Country{
public:
    Army();
    ~Army();

    // For iterator
    void createMedicUnit();
    void createGroundUnit();
    void createAirUnit();

    void Attack(Country*);
    void Retreat();

    // For Observer
    void update();

private:
    MedicUnit *medicUnit;
    GroundUnit *groundUnit;
    AirUnit *airUnit;
};

#endif