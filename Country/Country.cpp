#include "Country.h"

/**
 * @brief Construct a new Country:: Country object
 * Create army and initialize countries funds
 * We can have a input value for the funds that a country will have
 * But for now its going to be all the same
 */
Country::Country(double fund)
{
    alliance=NULL;
    funds = fund;
    createArmy();
    observedState = new Seize();
} 

/**
 * @brief Construct a new Country:: Country object
 * 
 * @param n 
 * @param f 
 */
Country::Country(std::string n,double f)
{ 
    alliance=NULL;
    name=n; 
    funds=f;
    createArmy(); 
    observedState=new Seize();
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
 * @brief Attack function, calculates total power then calls takeDamage on enemy Country
 * 
 * @param c Enemy country being attacked
 *  
 */
void Country::Attack(Country* c)
{
    std::cout << name << " is attacking "<<c->getName()<<"\n";
    int power=ARMY->Attack();
    power*=observedState->attackMethod();
    c->takeDamage(power);

    // Decrease countries funds
    funds-= ( (std::rand() % 10000)+5000) ;

    //Check for state change   
    Phase* temp=observedState->handleChange(funds); 
    delete observedState; 
    observedState=temp;

    //Contact allies
    notify();
    
}

/**
 * @brief Function called by an attacking Country.Function subtracts defense from enemy's attack to 
 * get overall damage done to army and removes soldiers
 * 
 * @param attack 
 */
void Country::takeDamage(int attack)
{ 
    int defense=ARMY->Defend(); 
    int damage=attack-defense;  
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
 * @param fund 
 */
void Country::addFunds(double fund)
{
    funds += fund;
}

/**
 * @brief Function that indicates country has surrendered.Country surrenders when power reaches 0
 * 
 * @return true 
 * @return false 
 */

bool Country::surrender()
{
    if(ARMY->Attack()==0){
       std::cout<<name; 
       ARMY->Surrender();
       return true;  
    }
    return false;   
}

/**
 * @brief Joins an alliance
 * 
 * @param all an alliance 
 */
void Country::joinAlliance(Alliance* all)
{ 
  alliance=all;
  alliance->addAlliance(this); 
} 

/**
 * @brief Contacts allied forces
 * 
 */
void Country::notify()
{ 
    if(alliance!=NULL)
    {
      alliance->removeAlliance(this);
      alliance->update(); 
      alliance->addAlliance(this); 
    }
}
