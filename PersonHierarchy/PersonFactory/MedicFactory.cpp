#include "MedicFactory.h"
#include "../Medic.h"

MedicFactory::MedicFactory(){}

MedicFactory::~MedicFactory(){}

Person* MedicFactory::createPerson(int i){
    return new Medic(i);
}