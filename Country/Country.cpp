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
    observedState = nullptr;
}

/**
 * @brief Destroy the Country:: Country object
 * deletes army and observed state if there is an observed state currently in that variable
 */
Country::~Country()
{
    delete ARMY;
    if(observedState != nullptr){
        delete observedState;
    }
}

/**
 * @brief used to set the name of this country object to the input param n
 * 
 * @param n 
 */
void Country::setName(std::string n)
{
    name = n;
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
    if(funds > 1000 && funds <= 10000){
        ARMY = new Army(funds/10,funds/100,funds/500);
    }else if(funds <= 50000 && funds > 10000){
        ARMY = new Army(funds/10,funds/100,funds/500);
    }else if(funds > 50000){
        ARMY = new Army(funds/10,funds/100,funds/500);
    }
}

/**
 * @brief Attack function to state that this country is going to attack the opposing country
 * 
 */
void Country::Attack()
{
    std::cout << name << ": ";
    ARMY->Attack();
    // Decrease countries funds
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
 * @param fund 
 */
void Country::addFunds(double fund)
{
    funds += fund;
}

/**
 * @brief 
 * 
 * @return Phase* 
 */
Phase* Country::update(){

}
