#ifndef MEDICUNIT_H
#define MEDICUNIT_H

#include "Unit.h"
#include "../PersonHierarchy/Medic.h"
#include "../PersonHierarchy/PersonFactory/MedicFactory.h"
#include "Iterator/MedicUnitIterator.h"
#include "Transport/ArmouredTruckMaker.h"
#include "Transport/ArmouredTruck.h"

class MedicUnit : public Unit
{
    private:
    std::list<Person *> unit;
    ArmouredTruckMaker* trans;
    ArmouredTruck* truck;

    public:
    MedicUnit(string);
    ~MedicUnit();
    void populateUnit(int);
    ArmyIterator *createIterator();
    int getHealPower(); 
};

#endif