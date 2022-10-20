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

void ArmouredTruckMaker:: buildProduct() // assemble transport
{
    this->addDefence("Armoured Plates");
    this->setHealth(500);
}

ArmouredTruck* ArmouredTruckMaker:: getProduct() // build and return new transport
{
    this->buildProduct();
    return truck;
}

ArmouredTruckMaker:: ~ArmouredTruckMaker() //Deallocate vehicle memory
{
    if(truck != NULL)
    {
        delete truck;
        truck = NULL;
    } 
}