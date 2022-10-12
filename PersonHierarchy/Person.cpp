#include "Person.h"

//int Person::CurrentID = 0;

Person::Person() : Country(){
    CurrentID++;
}

Person::~Person(){
    std::cout<<"ID: " << CurrentID << "Deleted\n";
}

int Person::getID(){
    return CurrentID;
}