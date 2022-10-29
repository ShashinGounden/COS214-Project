#include "Medic.h"
#include<string>

Medic::Medic(int id, int i, string s) : Person(id, i, s){}

Medic::~Medic(){}

Person* Medic::clone()
{
    return new Medic(getID(), getHealth(), getSkill());
}

/**
 * @brief 
 * 
 * Returns value of medics healing
 * 
 * @return int 
 */
int Medic::heal()
{
   return 20;
}
