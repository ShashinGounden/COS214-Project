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
    allianceList = new Alliance();
}

Country::~Country()
{
    delete ARMY;
    delete allianceList;
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
 * @brief Adding a country to Alliance objects list using Alliance's addAlliance function
 * Also to add this country as an alliance to the country being added to this allianceList 
 * @param c 
 */
void Country::addAlliance(Country* c){
    allianceList->addAlliance(c);
    c->addAlliance(this);
}

void Country::removeAlliance(Country* c){
    allianceList->removeAlliance(c);
    c->removeAlliance(this);
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
