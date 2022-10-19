#include "Medic.h"

Medic::Medic(int i) : Person(i)
{
    id = i;
}

Medic::~Medic()
{
    std::cout << "ID: " << id << " Deleted\n";
}

void Medic::Attack(){}

void Medic::Retreat()
{
    if (id % 13 == 0)
    {
        std::cout << "RETREAT!\n";
    }
}

Person* Medic::clone(){
    return new Medic(getID());
}

/**
 * @brief Medics function to heal a Person object
 * Using the parameters to add health to a Person Object
 * if the Person's health is lower than 0 or 0 then they
 * have died and we return false
 * else they can get their wounds mended by the medic
 * return true if their wounds have been mended
 * 
 * @param p 
 * @param healAmount 
 * @return true 
 * @return false 
 */
bool Medic::heal(Person* p, int healAmount){
    if(p->getHealth() <= 0){
        std::cout<<p->getID()<<" has died\n";
        return false;
    }else{
        if(p->getHealth() + healAmount > 100){
            p->addHealth(100-p->getHealth());
            return true;
        }else p->addHealth(healAmount);
    }
    return false;
}


/**
 * @brief getter for the ID variable
 * 
 * @return int 
 */
int Medic::getID()
{
    return id;
}