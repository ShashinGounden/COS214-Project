#include "Civilian.h"

Civilian::Civilian() : Person(){
    id = this->getID();
}

void Civilian::Attack(Country* c){}

void Civilian::applyMedication(){}

void Civilian::Retreat(){}
