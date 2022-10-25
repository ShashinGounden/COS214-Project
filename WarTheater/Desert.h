#ifndef DESERT_H
#define DESERT_H

#include "WarTheater.h"

class Desert : public WarTheater
{
public:
    Desert();
    ~Desert();

private:
     void add(Country* force)=0;
     void remove(Country* force) = 0;
     void warLoop() = 0;
};

#endif