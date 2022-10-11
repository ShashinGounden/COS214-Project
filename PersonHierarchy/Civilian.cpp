#include "Civilian.h"

Civilian::Civilian() : Person(){
    id = this->getID();
}

void Civilian::attack(){}

void Civilian::applyMedication(){}

void Civilian::retreat(){}
