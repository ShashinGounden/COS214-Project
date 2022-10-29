#include "GroundUnit.h"

/**
 * @brief Construct a new Ground Unit:: Ground Unit object
 * Create a soldier factory to then create soldier objects to pushback to
 * the unit object
 */
GroundUnit::GroundUnit() : Unit()
{
    rifleFac = new RifleFactory();
    pistolFac = new PistolFactory();
    boomFac = new ExplosiveFactory();
    factory = new SoldierFactory();
    tankBuilder = new TankMaker();
}

GroundUnit::~GroundUnit()
{
    /**
     * @brief - Delete all person objects in unit list object
     *
     */
    for (auto it = unit.begin(); it != unit.end(); it++)
    {
        delete (*it);
    }

    delete factory;
    delete rifleFac;
    delete pistolFac;
    delete boomFac;
    delete tankBuilder;

    if(tank != NULL)
    {
        delete tank;
    }
}

void GroundUnit::populateUnit(int numOfSoldiers)
{
    int ran = std::rand() % 10;

    for(int i = 0; i < numOfSoldiers; i++)
    {
        Weapon* tempW;

        if(ran == 0){
            tempW = boomFac->CreateLongRange();
        }
        else if(ran == 5){
            tempW = boomFac->CreateShortRange();
        }
        else if(ran == 1 || ran == 2)
        {
            tempW = rifleFac->CreateLongRange();
        }
        else if(ran == 3 || ran == 4)
        {
            tempW = rifleFac->CreateShortRange();
        }
        else if(ran == 6 || ran == 7)
        {
            tempW = PistolFac->CreateLongRange();
        }
        else
        {
            tempW = PistolFac->CreateShortRange();
        }
            
        Soldier* temp = factory->createPerson(rand(), 100, "fight");
        temp->addWeapon(tempW);

        unit.push_back(temp);
    }

    tank = tankBuilder->getProduct();
}

int GroundUnit:: getPower()
{ 
    int total = 0; 
    for(auto it = unit.begin(); it != unit.end(); it++)
    {
        total += it->weapon.fire();
    }
    return total;
}

ArmyIterator *GroundUnit::createIterator()
{
    return new GroundUnitIterator(unit);
} 

/**
 * @brief Deletes from list of soldiers
 * 
 */
void GroundUnit::remove(){ 
    if(unit.size()>0)
       unit.pop_front();
}


