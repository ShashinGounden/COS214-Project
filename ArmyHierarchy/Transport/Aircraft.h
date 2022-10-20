#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Transport.h"

using namespace std;

class Aircraft: public Transport
{
    protected:
    int damage;

	public:
	Aircraft();
    void setPower(int);
	~Aircraft();
};
#endif