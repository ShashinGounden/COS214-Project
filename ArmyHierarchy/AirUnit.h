#ifndef AIRUNIT_H
#define AIRUNIT_H

#include "Unit.h"
#include "../PersonHierarchy/Soldier.h"
#include "../PersonHierarchy/PersonFactory/SoldierFactory.h"
#include "Iterator/AirUnitIterator.h"
#include "../WeaponHierarchy/ExplosiveFactory.h"
#include "../WeaponHierarchy/RifleFactory.h"
#include "../WeaponHierarchy/PistolFactory.h"
#include "Transport/AircraftMaker.h"
#include "Transport/Aircraft.h"


class AirUnit : public Unit
{
    private:
    std::list<Person *> unit;
    WeaponFactory* weaponFactory;
    AircraftMaker* jetBuilder;
    Aircraft* jet;

    public:
    AirUnit(string);
    ~AirUnit();
    void populateUnit(int);
    ArmyIterator *createIterator();
    int getSize();
    int getPower(); 
    void remove();
};

#endif