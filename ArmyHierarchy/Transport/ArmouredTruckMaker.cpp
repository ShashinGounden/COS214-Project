#include"TransportBuilder.h"
#include"ArmouredTruckMaker.h"
#include"ArmouredTruck.h"
#include"Transport.h"
#include<string>

using namespace std;

ArmouredTruckMaker:: ArmouredTruckMaker()
{
    truck = new ArmouredTruck();
}

void ArmouredTruckMaker:: addDefence(string s)
{
    truck->setDefence(s);
}

void ArmouredTruckMaker:: setHealth(int h)
{
    truck->setHealth(h);
}

string ArmouredTruckMaker:: getDefence()
{
    return truck->getDefence();
}

int ArmouredTruckMaker:: getHealth()
{
    return truck->getHealth();
}

void ArmouredTruckMaker:: buildProduct()
{
    this->addDefence("Armoured Plates");
    this->setHealth(500);
}

Armouredtruck* ArmouredTruckMaker:: getProduct()
{
    this->buildProduct();
    return truck;
}

ArmouredTruckMaker:: ~ArmouredTruckMaker(){}