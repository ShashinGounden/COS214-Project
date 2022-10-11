#ifndef GROUNDUNIT_H
#define GROUNDUNIT_H

#include "Unit.h"
#include "../PersonHierarchy/Soldier.h"

class GroundUnit : public Unit
{
public:
    GroundUnit();
    ~GroundUnit();

    ArmyIterator *createIterator();

private:
    std::list<Person *> unit;
};
#endif