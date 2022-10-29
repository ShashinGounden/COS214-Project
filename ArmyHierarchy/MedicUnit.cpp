#include "MedicUnit.h"

/**
 * @brief Construct a new Medic Unit:: Medic Unit object
 * Create a medic factory to then create medic objects to pushback to
 * the unit object
 */
MedicUnit::MedicUnit()
{
    trans = new ArmouredTruckMaker();
}

MedicUnit::~MedicUnit()
{
    /**
     * @brief - Delete all person objects in unit list object
     *
     */
    for(auto it = list.begin(); it != list.end(); it++)
    {
        delete(*it);
    }

    delete factory;
    delete trans;

    if(truck != NULL)
    {
        delete truck;
    }
}

void MedicUnit::populateUnit(int numOfMedics)
{
    factory = new MedicFactory();

    for(int i = 0; i < numOfMedics; i++)
    {
        list.push_back(factory->createPerson(100, "heal people"));
    }

    truck = trans->getProduct();
}

ArmyIterator *MedicUnit::createIterator()
{
    return new MedicUnitIterator(list);
}

int MedicUnit:: getHealPower()  // Add up total healing power of medics list
{
    int total = 0;

    for(auto it = list.begin(); it != list.end(); it++)
    {
        total += it->heal();
    }

    return total;
}

