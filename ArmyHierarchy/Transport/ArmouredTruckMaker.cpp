#include "ArmouredTruckMaker.h"

ArmouredTruckMaker::ArmouredTruckMaker() {}

void ArmouredTruckMaker::addDefence(std::string s)
{
    truck->setDefence(s);
}

void ArmouredTruckMaker::setHealth(int h)
{
    truck->setHealth(h);
}

void ArmouredTruckMaker::buildProduct() // assemble transport
{
    this->addDefence("Armoured Plates");
    this->setHealth(500);
}

ArmouredTruck *ArmouredTruckMaker::getProduct() // build and return new transport
{
    truck = new ArmouredTruck();

    this->buildProduct();

    ArmouredTruck *temp = truck;
    truck = NULL;

    return temp;
}

ArmouredTruckMaker::~ArmouredTruckMaker() // Deallocate vehicle memory
{
    if (truck != NULL)
    {
        delete truck;
        truck = NULL;
    }
}