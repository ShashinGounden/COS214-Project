#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>

class Transport
{
	protected:
	int health;
    std::string defence;

	public:
	Transport();
	void setHealth(int);
    void setDefence(std::string);
    int getHealth();
    std::string getDefence();
	virtual ~Transport();
};

#endif