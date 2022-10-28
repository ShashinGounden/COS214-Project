#ifndef UNIT_H
#define UNIT_H

#include "Iterator/ArmyIterator.h"
#include "Iterator/AirUnitIterator.h"
#include "Iterator/GroundUnitIterator.h"
#include "Iterator/MedicUnitIterator.h"
#include <cstdlib>

class Unit
{
public:
    Unit();
    virtual ~Unit();
    
    virtual void populateUnit(int) = 0;
    virtual ArmyIterator *createIterator() = 0; 
    virtual int getPower() = 0;

protected:
    // Transport* transport;
    // TransportBuilder* builder;
};

#endif