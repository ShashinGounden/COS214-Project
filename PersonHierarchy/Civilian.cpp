#include "Civilian.h"

Civilian::Civilian(int i) : Person(i){
    id = i;
}

Civilian::~Civilian(){
    std::cout<<"ID: "<<id<<" Deleted\n";
}

void Civilian::Attack(){}

void Civilian::applyMedication(){}

void Civilian::Retreat(){}

int Civilian::getID(){
    return id;
}