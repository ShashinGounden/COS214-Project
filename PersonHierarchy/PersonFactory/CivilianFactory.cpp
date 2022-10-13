#include "CivilianFactory.h"
#include "../Civilian.h"

CivilianFactory::CivilianFactory(){}

CivilianFactory::~CivilianFactory(){}

Person* CivilianFactory::createPerson(int i){
    return new Civilian(i);
}