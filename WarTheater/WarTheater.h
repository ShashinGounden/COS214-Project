#ifndef WARTHEATER_H
#define WARTHEATER_H
#include "../Country/Country.h"
class WarTheater
{
public:
    WarTheater();
    //making the base class destructor virtual to avoid segmentation faults when deleting children class objects
    virtual ~WarTheater();

    //Pure virtual functions to be implemented in the children classes (Airspace and Sea)
    virtual void add(Country* force)=0;
    virtual void remove(Country* force) = 0;
    virtual void warLoop() = 0;
protected:
    //should this be a list?
    Country* countries;
};

#endif