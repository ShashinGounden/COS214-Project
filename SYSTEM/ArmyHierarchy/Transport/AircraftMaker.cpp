#include"TransportBuilder.h"
#include"AircraftMaker.h"
#include"Aircraft.h"
#include"Transport.h"

/**
 * @brief Construct AirCraft object
 * 
 * @return AircraftMaker:: 
 */
AircraftMaker:: AircraftMaker(){}

/**
 * @brief sets the jet objects defence attribute
 * 
 * @param s 
 */
void AircraftMaker:: addDefence(std::string s)
{
    jet->setDefence(s);
}

/**
 * @brief Set the jet objects health
 * 
 * @param h 
 */
void AircraftMaker:: setHealth(int h)
{
    jet->setHealth(h);
}

/**
 * @brief sets the damage that a jet can execute
 * 
 * @param j 
 */
void AircraftMaker:: addDamage(int j)
{
    jet->setPower(j);
}

/**
 * @brief assembles the aircraft
 * 
 */
void AircraftMaker:: buildProduct() //assemble
{
    this->addDefence("Stealth");
    this->setHealth(500);
    this->addDamage(500);
}

/**
 * @brief Calls build to assemble aircraft and returns the created object
 * 
 * @return Aircraft* 
 */
Aircraft* AircraftMaker:: getProduct() //build and return product
{
    jet = new Aircraft();

    this->buildProduct();
    
    Aircraft* temp = jet;
    jet = NULL;

    return temp;
}

/**
 * @brief destroy vehicles allocated memory
 * 
 * @return AircraftMaker:: 
 */
AircraftMaker:: ~AircraftMaker() // deallocate vehicle meory
{
    if(jet != NULL)
    {
        delete jet;
        jet = NULL;
    }
}