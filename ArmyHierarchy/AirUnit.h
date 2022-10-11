#ifndef AIRUNIT_H
#define AIRUNIT_H

#include "Unit.h"
#include "../PersonHierarchy/Soldier.h"

class AirUnit : public Unit
{
public:
    AirUnit();
    ~AirUnit();

    ArmyIterator *createIterator();

private:
    std::list<Person *> unit;
};

#endif