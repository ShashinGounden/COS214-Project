#include "AirUnit.h"

/**
 * @brief Construct a new Ground Unit:: Ground Unit object
 * Create a soldier factory to then create soldier objects to pushback to
 * the unit object
 */
AirUnit::AirUnit() : Unit()
{
    factory = new SoldierFactory();
    // rifleFac = new RifleFactory();
    // pistolFac = new PistolFactory();
    // boomFac = new ExplosiveFactory();
    weaponFactory = nullptr;
    jetBuilder = new AircraftMaker();
}

AirUnit::~AirUnit()
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
    delete jetBuilder;

    if (jet != NULL)
    {
        delete weaponFactory;
        delete jet;
    }
}

void AirUnit::populateUnit(int numOfPilots)
{
    int ran = std::rand() % 10;

    for (int i = 0; i < numOfPilots; i++)
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

    jet = jetBuilder->getProduct();
}

int AirUnit::getPower()
{
    int total = 0;
    for (auto it = unit.begin(); it != unit.end(); it++)
    {
        total += (*it)->getWeapon()->fire();
    }
    return total;
}

/**
 * @brief returns iterator object
 *
 * @return ArmyIterator*
 */
ArmyIterator *AirUnit::createIterator()
{
    return new AirUnitIterator(unit);
}

/**
 * @brief Deletes from list of soldiers
 *
 */
void AirUnit::remove()
{
    if (unit.size() > 0)
    {
        unit.pop_front();
    }
}
