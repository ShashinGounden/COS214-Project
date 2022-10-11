#ifndef UNIT_H
#define UNIT_H

#include "Iterator/ArmyIterator.h"

class Unit
{
public:
    Unit();
    virtual ~Unit();

    virtual ArmyIterator *createIterator() = 0;
};

#endif