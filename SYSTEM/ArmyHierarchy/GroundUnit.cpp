#include "GroundUnit.h"

/**
 * @brief Construct a new Ground Unit:: Ground Unit object
 * Create a soldier factory to then create soldier objects to pushback to
 * the unit object
 */
GroundUnit::GroundUnit(string name) : Unit(name)
{
    weaponFactory = nullptr;
    factory = new SoldierFactory();
    tankBuilder = new TankMaker();

    tank = tankBuilder->getProduct();

    cout <<this->cName<< "'s Ground unit keep their tanks on standby." << endl;
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
    delete tankBuilder;

    if (tank != NULL)
    {
        delete tank;
        tank = NULL;
    }
}

/**
 * @brief create a number of soldiers and give each one a weapon.
 * weapons are created upon a random probability. 20% explosives
 * 40% rifles and pistols, and of those a 50% chance of the type
 * of weapon being a long or short range variant.
 *
 * @param numOfSoldiers
 */
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

            delete weaponFactory;
            weaponFactory = NULL;
        }
        else if (ran == 5)
        {
            weaponFactory = new ExplosiveFactory();
            tempW = weaponFactory->CreateShortRange();

            delete weaponFactory;
            weaponFactory = NULL;
        }
        else if (ran == 1 || ran == 2)
        {
            weaponFactory = new RifleFactory();
            tempW = weaponFactory->CreateLongRange();

            delete weaponFactory;
            weaponFactory = NULL;
        }
        else if (ran == 3 || ran == 4)
        {
            weaponFactory = new RifleFactory();
            tempW = weaponFactory->CreateShortRange();

            delete weaponFactory;
            weaponFactory = NULL;
        }
        else if (ran == 6 || ran == 7)
        {
            weaponFactory = new PistolFactory();
            tempW = weaponFactory->CreateLongRange();

            delete weaponFactory;
            weaponFactory = NULL;
        }
        else
        {
            weaponFactory = new PistolFactory();
            tempW = weaponFactory->CreateShortRange();

            delete weaponFactory;
            weaponFactory = NULL;
        }

        Person *temp = factory->createPerson(rand(), 100, "fight");
        temp->addWeapon(tempW);

        unit.push_back(temp);
    }
}

/**
 * @brief Return size of unit
 *
 * @return int
 */
int GroundUnit::getSize()
{
    return unit.size();
}

/**
 * @brief calculate the total firepower of unit by adding each soldiers weapons
 * firepower.
 *
 * @return int
 */
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
        if (unit.front() != nullptr)
        {
            Person *p = unit.front();
            unit.pop_front();
            delete p;
        }
    }
}
