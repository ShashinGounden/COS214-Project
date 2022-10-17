#ifndef AIRUNIT_H
#define AIRUNIT_H

#include "Unit.h"
#include "../PersonHierarchy/Soldier.h"
#include "../PersonHierarchy/PersonFactory/SoldierFactory.h"
#include "Iterator/AirUnitIterator.h"

class AirUnit : public Unit
{
public:
    AirUnit();
    ~AirUnit();

    void populateUnit();
    ArmyIterator *createIterator();

protected:
    PersonFactory* factory;

private:
    std::list<Person *> unit;
};

#endif