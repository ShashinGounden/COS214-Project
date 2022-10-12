#include "Soldier.h"

Soldier::Soldier() : Person(){
    id = this->getID();
}

void Soldier::Attack(Country* c){
    if(id%5 == 0){
        std::cout<<"ATTACK!\n";
    }
}

void Soldier::applyMedication(){}

void Soldier::Retreat(){
    if(id%3 == 0){
        std::cout<<"RETREAT!\n";
    }
}
