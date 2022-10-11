#include "Medic.h"

Medic::Medic() : Person(){
    id = this->getID();
}

void Medic::attack(){
    if(id%2 == 0){
        std::cout<<"Prepares to aid injured soldiers\n";
    }
}

void Medic::applyMedication(){
    if(id%3 == 0){
        std::cout<<"Applies bandages to wounded soldier\n";
    }else if(id%5 == 0){
        std::cout<<"Applies morphine to injured soldier\n";
    }else{
        std::cout<<"Sutures soldiers wounds\n";
    }
}

void Medic::retreat(){
    if(id%6 == 0){
        std::cout<<"RETREAT!\n";
    }
}
