#include "TankMaker.h"

TankMaker::TankMaker() {}

/**
 * @brief SEts tanks defence
 * 
 * @param s 
 */
void TankMaker::addDefence(std::string s)
{
    tank->setDefence(s);
}

/**
 * @brief Sets tanks health
 * 
 * @param h 
 */
void TankMaker::setHealth(int h)
{
    tank->setHealth(h);
}

/**
 * @brief Adds secondary weapon to tank
 * 
 * @param s 
 */
void TankMaker::addSecondary(std::string s)
{
    tank->setSecondary(s);
}

/**
 * @brief Assembles new tank
 * 
 */
void TankMaker::buildProduct() // Assemble product
{
    this->addDefence("Armour");
    this->setHealth(500);
    this->addSecondary("gunner turret");
}

/**
 * @brief Assembles and rerturns newly created tank
 * 
 * @return Tank* 
 */
Tank *TankMaker::getProduct() // build and return new transport
{
    tank = new Tank();

    this->buildProduct();

    Tank *temp = tank;
    tank = NULL;

    return temp;
}

/**
 * @brief destroy vehicles allocated memory
 * 
 * @return TankMaker:: 
 */
TankMaker::~TankMaker() // deallocate vehicle
{
    if (tank != NULL)
    {
        delete tank;
        tank = NULL;
    }
}