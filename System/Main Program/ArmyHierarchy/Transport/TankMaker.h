#ifndef TANKMAKER_H
#define TANKMAKER_H

#include "TransportBuilder.h"
#include "Tank.h"

class TankMaker : public TransportBuilder
{
protected:
    Tank *tank;

public:
    TankMaker();
    void addDefence(std::string);
    void setHealth(int);
    void addSecondary(std::string);
    void buildProduct();
    Tank *getProduct();
    ~TankMaker();
};

#endif