#ifndef TRANSPORTBUILDER_H
#define TRANSPORTBUILDER_H

#include<string>
#include"Transport.h"

using namespace std;

class TransportBuilder
{
	public:
	TransportBuilder();
	virtual void addDefence(string)=0;
    virtual void setHealth(int)=0;
	~TransportBuilder();
};

#endif