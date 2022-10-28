#ifndef UNIT_H
#define UNIT_H

#include "Iterator/ArmyIterator.h"
#include "Iterator/AirUnitIterator.h"
#include "Iterator/GroundUnitIterator.h"
#include "Iterator/MedicUnitIterator.h"
#include "../PersonHierarchy/PersonFactory/PersonFactory.h"
#include <cstdlib>

class Unit
{
    public:
    Unit();
    virtual ~Unit();
    virtual void populateUnit(int) = 0;
    virtual ArmyIterator *createIterator() = 0;

    protected:
    PersonFactory* factory;
};

#endif