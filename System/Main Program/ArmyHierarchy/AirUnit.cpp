#include "AirUnit.h"

/**
 * @brief Construct a new Ground Unit:: Ground Unit object
 * Create a soldier factory to then create soldier objects to pushback to
 * the unit object
 */
AirUnit::AirUnit(string name) : Unit(name)
{
    factory = new SoldierFactory();
    weaponFactory = nullptr;
    jetBuilder = new AircraftMaker();

    jet = jetBuilder->getProduct();
    cout << this->cName << "'s Air unit has prepared its fleet of jets." << endl;
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
    delete jetBuilder;

    if (jet != NULL)
    {
        delete jet;
        jet = NULL;
    }
}

/**
 * @brief create a number of soldiers and give each one a weapon.
 * weapons are created upon a random probability. 20% explosives
 * 40% rifles and pistols, and of those a 50% chance of the type
 * of weapon being a long or short range variant.
 *
 * @param numOfPilots
 */
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
 * @brief return size of unit
 *
 * @return int
 */
int AirUnit::getSize()
{
    return unit.size();
}

/**
 * @brief calculate the total firepower of unit by adding each soldiers weapons
 * firepower.
 *
 * @return int
 */
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
        if (unit.front() != nullptr)
        {
            Person *p = unit.front();
            unit.pop_front();
            delete p;
        }
    }
}
