#ifndef TANK_H
#define TANK_H

#include "Transport.h"

class Tank: public Transport
{
    protected:
    std::string secondaryWeapon;

	public:
	Tank();
    void setSecondary(std::string);
	~Tank();
};
#endif