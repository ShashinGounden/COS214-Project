#include"TransportBuilder.h"
#include"AircraftMaker.h"
#include"Aircraft.h"
#include"Transport.h"
#include<string>

using namespace std;

AircraftMaker:: AircraftMaker()
{
    jet = new Aircraft();
}

void AircraftMaker:: addDefence(string s)
{
    jet->setDefence(s);
}

void AircraftMaker:: setHealth(int h)
{
    jet->setHealth(h);
}

string AircraftMaker:: getDefence()
{
    return jet->getDefence();
}

int AircraftMaker:: getHealth()
{
    return jet->getHealth();
}

void AircraftMaker:: addDamage(int j)
{
    jet->setPower(j);
}

void AircraftMaker:: buildProduct()
{
    this->addDefence("Armour");
    this->setHealth(500);
    this->addDamage(500);
}

jet* AircraftMaker:: getProduct()
{
    this->buildProduct();
    return jet;
}

AircraftMaker:: ~AircraftMaker(){}