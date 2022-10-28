#include "Person.h"

/**
 * @brief Construct a new Person:: Person object
 * 
 * @param i 
 */
Person::Person(int i){
    hp = 100;
}

Person::~Person()
{
    if(weapon != NULL)
    {
        delete weapon;
        weapon = NULL;
    }
}

void Person::addHealth(int h){
    hp+=h;
}

int Person::getHealth(){
    return hp;
}

int Person::takeDamage(int d){
    hp-=d;
    return hp;
}

