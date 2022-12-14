/**
 * @file Country.cpp
 * @brief Main Country object
 * In place for the country in the battles
 * @version 5.11
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Country.h"
#include "Alliance.h"

/**
 * @brief Construct a new Country:: Country object
 *
 * @param n
 * @param f
 */
Country::Country(std::string n, double f)
{
    alliance = NULL;
    name = n;
    funds = f;
    std::cout << this->name + " has prepared their Army for battle!\n";
    createArmy();
    std::cout << name << " ";
    observedState = new Seize();
}

/**
 * @brief Destroy the Country:: Country object
 * deletes army and observed state if there is an observed state currently in that variable
 */
Country::~Country()
{
    if (ARMY != nullptr)
    {
        delete ARMY;
    }
    if (observedState != nullptr)
    {
        delete observedState;
    }
    if (alliance != nullptr)
    {
        delete alliance;
    }
}

/**
 * @brief returns the country's name
 *
 * @return std::string
 */
std::string Country::getName()
{
    return name;
}

/**
 * @brief Creating army object
 * Using the funds variable we createArmy with a specific amount of soldiers
 * first num = soldiers
 * second num = medics
 * third num = pilots
 */
void Country::createArmy()
{
    if (funds > 1000 && funds <= 10000)
    {
        ARMY = new Army(getName(), funds / 10, funds / 100, funds / 50);
    }
    else if (funds <= 50000 && funds > 10000)
    {
        ARMY = new Army(getName(), funds / 10, funds / 100, funds / 50);
    }
    else if (funds > 50000)
    {
        ARMY = new Army(getName(), funds / 10, funds / 100, funds / 50);
    }
    int totalSoldiers = (funds / 10) + (funds / 100) + (funds / 50);
    funds -= totalSoldiers * 3;
    std::cout << "Total Soldiers from " << name << ": " << totalSoldiers << "\n";
    std::cout << "\n";
}

/**
 * @brief Attack function, calculates total power then calls takeDamage on enemy Country
 *
 * @param c Enemy country being attacked
 *
 */
void Country::Attack(Country *c)
{   
    if(c->getNumOfSoldiers()==0)
       return;
    std::cout << name << " is attacking " << c->getName() << "\n";
    int power = ARMY->Attack();
    power *= observedState->attackMethod();
    c->takeDamage(power);

    // Decrease countries funds
    funds -= ((std::rand() % 20000) + 10000);

    // Check for state change
    std::cout << name << " ";
    Phase *temp = observedState->handleChange(funds);

    if (observedState != temp)
    {
        delete observedState;
    }

    observedState = temp;

    // Contact allies
    notify(); 
}

/**
 * @brief Function called by an attacking Country.Function subtracts defense from enemy's attack to
 * get overall damage done to army and removes soldiers
 *
 * @param attack damage value for enemy
 */
void Country::takeDamage(int attack)
{
    int defense = ARMY->Defend();
    
    int damage = (attack/100) - (defense/100);
    ARMY->RemoveSoldiers(damage);
}

/**
 * @brief Retreat function to tell the user that this country is retreating
 *
 */
void Country::Retreat()
{
    std::cout << name << ": ";
    ARMY->Retreat();
}

/**
 * @brief Returns the countries funds
 *
 * @return double
 */
double Country::getFunds()
{
    return funds;
}

/**
 * @brief This function will be used to add funds to the country's arsenal
 *
 * Will increase the number of soldiers in the units according to the funds being added
 * funds gets decreased by the number of soldiers created multiplied by 2
 *
 * @param fund
 */
void Country::addFunds(double fund)
{
    funds += fund;
    // Check for state change
    std::cout << name << " ";
    Phase *temp = observedState->handleChange(funds);

    // Add Soldiers accoring to funds value
    if (fund >= 1000)
    {
        ARMY->populateUnit(fund / 10, fund / 100, fund / 50);
        funds-= (fund/10 + fund/100 + fund/50)*2;
    }

    if (observedState != temp)
    {
        delete observedState;
    }

    observedState = temp;
}

/**
 * @brief Function that indicates country has surrendered.Country surrenders when power reaches 0
 *
 * @return true
 * @return false
 */

bool Country::surrender(Country *c)
{
    if (ARMY->Attack() <= 0)
    {
        ARMY->Surrender(c);
        return true;
    }
    return false;
}

/**
 * @brief Joins an alliance
 *
 * @param all an alliance
 */
void Country::joinAlliance(Alliance *all)
{
    alliance = all;
    alliance->addAlliance(this);
}

/**
 * @brief Contacts allied forces
 *
 */
void Country::notify()
{
    if (alliance != NULL)
    {
        alliance->removeAlliance(this);
        alliance->update();
        alliance->addAlliance(this);
    }
}
/**
 * @brief returns country object
 * 
 * @return Country* 
 */
Country* Country::getCountry(){
    return this;
}

/**
 * @brief used to calculate the number of soldiers left after the 
 * battle has ended
 * mainly for design mode to give an output of the 
 * number of soldiers that have died in battle
 * 
 * @return int 
 */
int Country::getNumOfSoldiers(){
    return ARMY->getNumOfSoldiers();
}