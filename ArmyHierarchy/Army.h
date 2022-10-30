#ifndef ARMY_H
#define ARMY_H

#include "MedicUnit.h"
#include "GroundUnit.h"
#include "AirUnit.h"
#include <string>

class Army
{
public:
    Army(std::string, int, int, int);
    ~Army();

    // For iterator
    void populateUnit(int, int, int);

    int Attack();
    void Advance();
    void Retreat();
    void Surrender();
    int Defend();
    void RemoveSoldiers(int);

    // For Observer
    void update();

    std::string getName();

private:
    MedicUnit *medicUnit;
    GroundUnit *groundUnit;
    AirUnit *airUnit;
    std::string countryName;
};

#endif