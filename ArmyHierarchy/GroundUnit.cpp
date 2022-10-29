#include "GroundUnit.h"

/**
 * @brief Construct a new Ground Unit:: Ground Unit object
 * Create a soldier factory to then create soldier objects to pushback to
 * the unit object
 */
GroundUnit::GroundUnit() : Unit()
{
    // rifleFac = new RifleFactory();
    // pistolFac = new PistolFactory();
    // boomFac = new ExplosiveFactory();
    weaponFactory = nullptr;
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
    // delete rifleFac;
    // delete pistolFac;
    // delete boomFac;
    delete tankBuilder;

    if (tank != NULL)
    {
        delete weaponFactory;
        delete tank;
    }
}

void GroundUnit::populateUnit(int numOfSoldiers)
{
    int ran = std::rand() % 10;

    for (int i = 0; i < numOfSoldiers; i++)
    {
        Weapon *tempW;

        if (ran == 0)
        {
            weaponFactory = new ExplosiveFactory();
            tempW = weaponFactory->CreateLongRange();
        }
        else if (ran == 5)
        {
            weaponFactory = new ExplosiveFactory();
            tempW = weaponFactory->CreateShortRange();
        }
        else if (ran == 1 || ran == 2)
        {
            weaponFactory = new RifleFactory();
            tempW = weaponFactory->CreateLongRange();
        }
        else if (ran == 3 || ran == 4)
        {
            weaponFactory = new RifleFactory();
            tempW = weaponFactory->CreateShortRange();
        }
        else if (ran == 6 || ran == 7)
        {
            weaponFactory = new PistolFactory();
            tempW = weaponFactory->CreateLongRange();
        }
        else
        {
            weaponFactory = new PistolFactory();
            tempW = weaponFactory->CreateShortRange();
        }

        Person *temp = factory->createPerson(rand(), 100, "fight");
        temp->addWeapon(tempW);

        unit.push_back(temp);
    }

    tank = tankBuilder->getProduct();
}

int GroundUnit::getPower()
{
    int total = 0;
    for (auto it = unit.begin(); it != unit.end(); it++)
    {
        total += (*it)->getWeapon()->fire();
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
void GroundUnit::remove()
{
    if (unit.size() > 0)
    {
        delete unit.front();
        unit.pop_front();
    }
}
