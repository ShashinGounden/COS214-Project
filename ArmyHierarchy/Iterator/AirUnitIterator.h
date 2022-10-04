#ifndef AIRUNITITERATOR_H
#define AIRUNITITERATOR_H

#include "ArmyIterator.h"

class AirUnitIterator : public ArmyIterator
{
public:
    AirUnitIterator(std::list<Person*>);
    ~AirUnitIterator();

    Person* first();
    Person* next();
    bool hasNext();
    Person* current();
    void increment();

private:
    Person* curr;
    std::list<Person*> unit;
};

#endif