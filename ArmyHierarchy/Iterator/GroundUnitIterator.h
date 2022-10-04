#ifndef GROUNDUNITITERATOR_H
#define GROUNDUNITITERATOR_H

#include "ArmyIterator.h"

class GroundUnitIterator : public ArmyIterator
{
public:
    GroundUnitIterator(std::list<Person*>);
    ~GroundUnitIterator();

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