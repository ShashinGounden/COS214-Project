#ifndef TANKMAKER_H
#define TANKMAKER_H

#include<string>
#include"Transport.h"
#include"Tank.h"

using namespace std;

class TankMaker: public TransportBuilder
{
    protected:
    Tank* tank;

	public:
	TankMaker();
	void addDefence(string);
    void setHealth(int);
    void addSecondary(string);
    void buildProduct();
    Tank* getProduct();
	~TankMaker();
};

#endif