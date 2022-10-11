#ifndef ARMY_H
#define ARMY_H

#include "../Country/Country.h"
#include "MedicUnit.h"
#include "GroundUnit.h"
#include "AirUnit.h"

class Army : public Country{
public:
    Army(std::string);
    ~Army();

    // For iterator
    void createMedicUnit();
    void createGroundUnit();
    void createAirUnit();

    void attack();
    void retreat();

    // For Observer
    void update();

private:
    MedicUnit *medicUnit;
    GroundUnit *groundUnit;
    AirUnit *airUnit;
};

#endif