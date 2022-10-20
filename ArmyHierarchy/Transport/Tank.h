#ifndef TANK_H
#define TANK_H

#include<string>
#include "Transport.h"

using namespace std;

class Tank: public Transport
{
    protected:
    string secondaryWeapon;

	public:
	Tank();
    void setSecondary(string);
	~Tank();
};
#endif