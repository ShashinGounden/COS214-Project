#ifndef AIRCRAFTMAKER_H
#define AIRCRAFTMAKER_H

#include<string>
#include"Transport.h"
#include"Aircraft.h"

using namespace std;

class AircraftMaker: public TransportBuilder
{
    protected:
    Aircraft* jet;

	public:
	AircraftMaker();
	void addDefence(string);
    void setHealth(int);
    void addDamage(int);
    void buildProduct();
    Aircraft* getProduct();
	~AircraftMaker();
};

#endif