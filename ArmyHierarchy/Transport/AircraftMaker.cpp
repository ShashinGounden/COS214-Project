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

void AircraftMaker:: addDamage(int j)
{
    jet->setPower(j);
}

void AircraftMaker:: buildProduct() //assemble
{
    this->addDefence("Stealth");
    this->setHealth(500);
    this->addDamage(500);
}

Aircraft* AircraftMaker:: getProduct() //build and return product
{
    this->buildProduct();
    return jet;
}

AircraftMaker:: ~AircraftMaker() // deallocate vehicle meory
{
    if(jet != NULL)
    {
        delete jet;
        jet = NULL;
    }
}