#include "CivilianFactory.h"
#include "../Civilian.h"

CivilianFactory::CivilianFactory(){}

CivilianFactory::~CivilianFactory(){}

Person* CivilianFactory::createPerson(){
    return new Civilian();
}