#include "Country.h"

Country::Country(std::string n){
    name = n;
    ARMY = new Army(n);
}

Country::~Country(){}

std::string Country::getName(){
    return name;
}

void Country::Attack(Country* country){
    ARMY->attack();
}