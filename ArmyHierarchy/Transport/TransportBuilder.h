#ifndef TRANSPORTBUILDER_H
#define TRANSPORTBUILDER_H

#include <string>
class TransportBuilder
{
public:
	TransportBuilder();
	virtual void addDefence(std::string) = 0;
	virtual void setHealth(int) = 0;
	virtual ~TransportBuilder();
};

#endif