#include "Country.h"

Country::Country(){
    ARMY = new Army();
}

Country::~Country(){}

void Country::setName(std::string n){
    name = n;
}

std::string Country::getName(){
    return name;
}

void Country::Attack(Country* country){
    ARMY->Attack(country);
}

void Country::Retreat(){
    ARMY->Retreat();
}