#ifndef TRANSPORT_H
#define TRANSPORT_H

#include<string>

using namespace std;

class Transport
{
	protected:
	int health;
    string defence;

	public:
	Transport();
	void setHealth(int);
    void setDefence(string);
    int getHealth();
    string getDefence();
	virtual ~Transport();
};

#endif