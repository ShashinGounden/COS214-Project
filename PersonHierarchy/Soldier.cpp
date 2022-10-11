#include "Soldier.h"

Soldier::Soldier() : Person(){
    id = this->getID();
}

void Soldier::attack(){
    if(id%5 == 0){
        std::cout<<"ATTACK!\n";
    }
}

void Soldier::applyMedication(){}

void Soldier::retreat(){
    if(id%3 == 0){
        std::cout<<"RETREAT!\n";
    }
}
