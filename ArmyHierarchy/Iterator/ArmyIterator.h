#ifndef ARMYITERATOR_H
#define ARMYITERATOR_H

#include <list>
#include <iostream>
#include "../../PersonHierarchy/Person.h"

class Person;
class ArmyIterator
{
public:
    ArmyIterator();
    virtual ~ArmyIterator();

    virtual Person *first() = 0;
    virtual Person *next() = 0;
    virtual bool hasNext() = 0;
    virtual Person *current() = 0;
    virtual void increment() = 0;
};

#endif