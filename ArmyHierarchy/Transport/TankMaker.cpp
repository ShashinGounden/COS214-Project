#include"TransportBuilder.h"
#include"TankMaker.h"
#include"Tank.h"
#include"Transport.h"
#include<string>

using namespace std;

TankMaker:: TankMaker()
{
    tank = new Tank();
}

void TankMaker:: addDefence(string s)
{
    tank->setDefence(s);
}

void TankMaker:: setHealth(int h)
{
    tank->setHealth(h);
}

void TankMaker:: addSecondary(string s)
{
    tank->setSecondary(s);
}

void TankMaker:: buildProduct() //Assemble product
{
    this->addDefence("Armour");
    this->setHealth(500);
    this->addSecondary("gunner turret");
}

Tank* TankMaker:: getProduct() //build and return new transport
{
    this->buildProduct();
    return tank;
}

TankMaker:: ~TankMaker() //deallocate vehicle
{
    if(tank != NULL)
    {
        delete tank;
        tank = NULL;
    }
}