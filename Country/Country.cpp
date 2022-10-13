#include "Country.h"

Country::Country(){
    createArmy();
}

Country::~Country(){
    delete ARMY;
}

void Country::setName(std::string n){
    name = n;
}

std::string Country::getName(){
    return name;
}

void Country::createArmy(){
    ARMY = new Army();
}

void Country::Attack(){
    ARMY->Attack();
}

void Country::Retreat(){
    ARMY->Retreat();
}