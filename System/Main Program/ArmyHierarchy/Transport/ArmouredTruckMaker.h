#ifndef ARMOUREDTRUCKMAKER_H
#define ARMOUREDTRUCKMAKER_H

#include "TransportBuilder.h"
#include "Transport.h"
#include "ArmouredTruck.h"

class ArmouredTruckMaker : public TransportBuilder
{
protected:
    ArmouredTruck *truck;

public:
    ArmouredTruckMaker();
    void addDefence(std::string);
    void setHealth(int);
    void buildProduct();
    ArmouredTruck *getProduct();
    ~ArmouredTruckMaker();
};

#endif