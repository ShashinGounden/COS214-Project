#include "Country.h"

/**
 * @brief Construct a new Country:: Country object
 * Create army and initialize countries funds
 * We can have a input value for the funds that a country will have
 * But for now its going to be all the same
 */
Country::Country(double fund)
{
    funds = fund;
    createArmy();
}

Country::~Country()
{
    delete ARMY;
}

void Country::setName(std::string n)
{
    name = n;
}

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
    if(funds <= 10000){
        ARMY = new Army(funds/10,10,5);
    }else if(funds <= 50000 && funds > 10000){
        ARMY = new Army(funds/10,50,25);
    }else if(funds > 50000){
        ARMY = new Army(funds/10,100,50);
    }
}

void Country::Attack()
{
    ARMY->Attack();
    // Decrease countries funds
}

void Country::Retreat()
{
    ARMY->Retreat();
}

double Country::getFunds()
{
    return funds;
}

void Country::addFunds(double fund)
{
    funds += fund;
}
