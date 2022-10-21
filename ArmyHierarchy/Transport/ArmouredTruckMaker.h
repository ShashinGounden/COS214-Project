#ifndef ARMOUREDTRUCKMAKER_H
#define ARMOUREDTRUCKMAKER_H

#include<string>
#include"Transport.h"
#include"ArmouredTruck.h"

using namespace std;

class ArmouredTruckMaker: public TransportBuilder
{
    protected:
    ArmouredTruck* truck;

	public:
	ArmouredTruckMaker();
	void addDefence(string);
    void setHealth(int);
    void buildProduct();
    ArmouredTruck* getProduct();
	~ArmouredTruckMaker();
};

#endif