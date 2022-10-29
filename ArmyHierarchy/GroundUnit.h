#ifndef GROUNDUNIT_H
#define GROUNDUNIT_H

#include "Unit.h"
#include "../PersonHierarchy/Soldier.h"
#include "../PersonHierarchy/PersonFactory/SoldierFactory.h"
#include "../WeaponHierarchy/ExplosiveFactory.h"
#include "../WeaponHierarchy/RifleFactory.h"
#include "../WeaponHierarchy/PistolFactory.h"
#include "Iterator/GroundUnitIterator.h"

class GroundUnit : public Unit
{
public:
    GroundUnit();
    ~GroundUnit();

    void populateUnit(int);
    ArmyIterator *createIterator();
    int getPower();

private:
    std::list<Person*> unit;
    RifleFactory* rifleFac;
    PistolFactory* pistolFac;
    ExplosiveFactory* boomFac;
};
#endif