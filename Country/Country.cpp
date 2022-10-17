#include "Country.h"

/**
 * @brief Construct a new Country:: Country object
 * Create army and initialize countries funds
 * We can have a input value for the funds that a country will have
 * But for now its going to be all the same
 */
Country::Country()
{
    funds = 100000.0;
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
 *
 */
void Country::createArmy()
{
    ARMY = new Army();
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
