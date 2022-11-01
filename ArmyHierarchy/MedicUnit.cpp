#include "MedicUnit.h"

/**
 * @brief Construct a new Medic Unit:: Medic Unit object
 * Create a medic factory to then create medic objects to pushback to
 * the unit object
 */
MedicUnit::MedicUnit()
{
    trans = new ArmouredTruckMaker();

    truck = trans->getProduct();
}

/**
 * @brief - Delete all person objects in unit object
 *
 */
MedicUnit::~MedicUnit()
{
    for (auto it = unit.begin(); it != unit.end(); it++)
    {
        delete (*it);
    }

    delete factory;
    delete trans;

    if (truck != NULL)
    {
        delete truck;
        truck = NULL;
    }
}

/**
 * @brief create a number of soldiers and give each one a weapon.
 * weapons are created upon a random probability. 20% explosives
 * 40% rifles and pistols, and of those a 50% chance of the type
 * of weapon being a long or short range variant.
 * 
 * @param numOfMedics 
 */
void MedicUnit::populateUnit(int numOfMedics)
{
    factory = new MedicFactory();

    for (int i = 0; i < numOfMedics; i++)
    {
        unit.push_back(factory->createPerson(rand(), 100, "heal people"));
    }
}

ArmyIterator *MedicUnit::createIterator()
{
    return new MedicUnitIterator(unit);
}

/**
 * @brief Calculate total healing power of medics unit by adding up all available medics
 * heal value.
 * 
 * @return int 
 */
int MedicUnit::getHealPower() // Add up total healing power of medics unit
{
    int total = 0;

    for (auto it = unit.begin(); it != unit.end(); it++)
    {
        total += (*it)->heal();
    }

    return total;
}
