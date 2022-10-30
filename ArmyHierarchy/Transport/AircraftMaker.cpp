#include"TransportBuilder.h"
#include"AircraftMaker.h"
#include"Aircraft.h"
#include"Transport.h"

AircraftMaker:: AircraftMaker(){}

void AircraftMaker:: addDefence(std::string s)
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
    jet = new Aircraft();

    this->buildProduct();
    
    Aircraft* temp = jet;
    jet = NULL;

    return temp;
}

AircraftMaker:: ~AircraftMaker() // deallocate vehicle meory
{
    if(jet != NULL)
    {
        delete jet;
        jet = NULL;
    }
}