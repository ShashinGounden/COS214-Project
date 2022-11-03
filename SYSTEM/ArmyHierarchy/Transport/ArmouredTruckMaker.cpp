#include "ArmouredTruckMaker.h"

/**
 * @brief Construct a new Armoured Truck Maker:: Armoured Truck Maker object
 * 
 */
ArmouredTruckMaker::ArmouredTruckMaker() {}

/**
 * @brief sets trucks defence
 * 
 * @param s 
 */
void ArmouredTruckMaker::addDefence(std::string s)
{
    truck->setDefence(s);
}

/**
 * @brief Sets trucks health
 * 
 * @param h 
 */
void ArmouredTruckMaker::setHealth(int h)
{
    truck->setHealth(h);
}

/**
 * @brief Assembles an armoured truck
 * 
 */
void ArmouredTruckMaker::buildProduct() // assemble transport
{
    this->addDefence("Armoured Plates");
    this->setHealth(500);
}

/**
 * @brief Build and return new armoured truck object
 * 
 * @return ArmouredTruck* 
 */
ArmouredTruck *ArmouredTruckMaker::getProduct() // build and return new transport
{
    truck = new ArmouredTruck();

    this->buildProduct();

    ArmouredTruck *temp = truck;
    truck = NULL;

    return temp;
}

/**
 * @brief destroy vehicles allocated memory
 * 
 * @return ArmouredTruckMaker:: 
 */
ArmouredTruckMaker::~ArmouredTruckMaker() // Deallocate vehicle memory
{
    if (truck != NULL)
    {
        delete truck;
        truck = NULL;
    }
}