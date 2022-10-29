#include "MedicFactory.h"
#include "../Medic.h"

MedicFactory::MedicFactory(){}

MedicFactory::~MedicFactory(){}

Person* MedicFactory::createPerson(int id, int i, string s)
{
    return new Medic(id, i, s);
}