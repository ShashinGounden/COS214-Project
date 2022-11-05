#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Transport.h"
#include <string>

class Aircraft : public Transport
{
protected:
    int damage;

public:
    Aircraft();
    void setPower(int);
    ~Aircraft();
};
#endif