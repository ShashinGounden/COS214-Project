#ifndef MEDICUNIT_H
#define MEDICUNIT_H

#include "Unit.h"
#include "../PersonHierarchy/Medic.h"
#include "../PersonHierarchy/PersonFactory/MedicFactory.h"
#include "Iterator/MedicUnitIterator.h"

class MedicUnit : public Unit
{
public:
    MedicUnit();
    ~MedicUnit();

    ArmyIterator *createIterator();

private:
    std::list<Person *> unit;
};

#endif