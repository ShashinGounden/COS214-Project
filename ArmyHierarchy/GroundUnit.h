#ifndef GROUNDUNIT_H
#define GROUNDUNIT_H

#include "Unit.h"
#include "../PersonHierarchy/Soldier.h"
#include "../PersonHierarchy/PersonFactory/SoldierFactory.h"
#include "../WeaponHierarchy/ExplosiveFactory.h"
#include "../WeaponHierarchy/RifleFactory.h"
#include "../WeaponHierarchy/PistolFactory.h"
#include "Iterator/GroundUnitIterator.h"
#include "Transport/TankMaker.h"
#include "Transport/Tank.h"

class GroundUnit : public Unit
{
    private:
    std::list<Person*> unit;
    WeaponFactory* weaponFactory;
    TankMaker* tankBuilder;
    Tank* tank;
    
    public:
    GroundUnit(string);
    ~GroundUnit();
    void populateUnit(int);
    ArmyIterator *createIterator();
    int getSize();
    int getPower(); 
    void remove();
};
#endif