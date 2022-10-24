#ifndef SEA_H
#define SEA_H

#include "WarTheater.h"

class Sea : public WarTheater
{
public:
    Sea();
    ~Sea();

private:
    //virtual functions to be implemented in .cpp file
     void add(Country* force);
     void remove(Country* force);
     void warLoop();
};

#endif