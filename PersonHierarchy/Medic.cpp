#include "Medic.h"
#include<string>

Medic::Medic(int i, string s) : Person(i, s){}

Medic::~Medic(){}

Person* Medic::clone()
{
    return new Medic(getHealth(), getSkill());
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
int Medic::heal()
{
   return 20;
}
