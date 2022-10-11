#ifndef UNIT_H
#define UNIT_H

#include "Iterator/ArmyIterator.h"
#include "Iterator/AirUnitIterator.h"
#include "Iterator/GroundUnitIterator.h"
#include "Iterator/MedicUnitIterator.h"

class Unit
{
public:
    Unit();
    virtual ~Unit();
    
    virtual ArmyIterator *createIterator() = 0;
};

#endif