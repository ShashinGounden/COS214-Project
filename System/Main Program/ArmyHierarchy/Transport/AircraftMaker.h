#ifndef AIRCRAFTMAKER_H
#define AIRCRAFTMAKER_H

#include "TransportBuilder.h"
#include "Aircraft.h"

class AircraftMaker : public TransportBuilder
{
protected:
    Aircraft *jet;

public:
    AircraftMaker();
    void addDefence(std::string);
    void setHealth(int);
    void addDamage(int);
    void buildProduct();
    Aircraft *getProduct();
    ~AircraftMaker();
};

#endif