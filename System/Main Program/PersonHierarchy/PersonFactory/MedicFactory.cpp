#include "MedicFactory.h"

MedicFactory::MedicFactory(){}

MedicFactory::~MedicFactory(){}

Person* MedicFactory::createPerson(int id, int i, std::string s)
{
    return new Medic(id, i, s);
}