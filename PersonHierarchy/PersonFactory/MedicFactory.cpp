#include "MedicFactory.h"
#include "../Medic.h"

MedicFactory::MedicFactory(){}

MedicFactory::~MedicFactory(){}

Person* MedicFactory::createPerson(int i, string s)
{
    return new Medic(i, s);
}