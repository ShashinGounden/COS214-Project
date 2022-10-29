#ifndef AIRUNIT_H
#define AIRUNIT_H

#include "Unit.h"
#include "../PersonHierarchy/Soldier.h"
#include "../PersonHierarchy/PersonFactory/SoldierFactory.h"
#include "Iterator/AirUnitIterator.h"
#include "../WeaponHierarchy/ExplosiveFactory.h"
#include "../WeaponHierarchy/RifleFactory.h"
#include "../WeaponHierarchy/PistolFactory.h"
#include "../ArmyHierarchy/Transport/AircraftMaker.h"
#include "../ArmyHierarchy/Transport/Aircraft.h"

class AirUnit : public Unit
{
    private:
    std::list<Person *> unit;
    RifleFactory* rifleFac;
    PistolFactory* pistolFac;
    ExplosiveFactory* boomFac;
    AircraftMaker* jetBuilder;
    Aircraft* jet;

    public:
    AirUnit();
    ~AirUnit();
    void populateUnit(int);
    ArmyIterator *createIterator();
    int getPower(); 
    void remove();
};

#endif