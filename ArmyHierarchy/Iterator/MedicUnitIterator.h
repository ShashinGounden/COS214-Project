#ifndef MEDICUNITITERATOR_H
#define MEDICUNITITERATOR_H

#include "ArmyIterator.h"
#include "../../PersonHierarchy/Medic.h"

class MedicUnitIterator : public ArmyIterator
{
public:
    MedicUnitIterator(std::list<Person *>);
    ~MedicUnitIterator();

    Person *first();
    Person *next();
    bool hasNext();
    Person *current();
    void increment();

private:
    Person *curr;
    std::list<Person *> unit;
};

#endif