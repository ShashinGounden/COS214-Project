#include "MedicFactory.h"
#include "../Medic.h"

MedicFactory::MedicFactory(){}

MedicFactory::~MedicFactory(){}

Person* MedicFactory::createPerson(){
    return new Medic();
}