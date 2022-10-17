#include "Army.h"

/**
 * @brief Construct a new Army:: Army object
 *  Instantiate all units
 *  Using populateUnit() to populate all Units
 */
Army::Army()
{
    std::cout << "Creating Army\n";
    MedicUnit *mUnit = new MedicUnit();
    medicUnit = mUnit;
    GroundUnit *gUnit = new GroundUnit();
    groundUnit = gUnit;
    AirUnit *aUnit = new AirUnit();
    airUnit = aUnit;

    populateUnit();
}

/**
 * @brief Destroy the Army:: Army object
 *
 */
Army::~Army()
{
    delete medicUnit;
    delete groundUnit;
    delete airUnit;
}

/**
 * @brief Creation of All Units
 *
 */
void Army::populateUnit(){
    groundUnit->populateUnit();
    medicUnit->populateUnit();
    airUnit->populateUnit();
}

/**
 * @brief All units and Soldiers attack
 *
 * @return cout statement from units attack method
 */
void Army::Attack()
{
    std::cout << "All soldiers ATTACK!\n";
    ArmyIterator *itGround = groundUnit->createIterator();
    ArmyIterator *itAir = airUnit->createIterator();
    ArmyIterator *itMedic = medicUnit->createIterator();

    while (itGround->hasNext())
    {
        itGround->current()->Attack();
        itGround->increment();
    }

    while (itAir->hasNext())
    {
        itAir->current()->Attack();
        itAir->increment();
    }
    std::cout << "MEDICS prepare the morphine!\n";
    while (itMedic->hasNext())
    {
        itMedic->current()->Attack();
        itMedic->increment();
    }

    /**
     * @brief Add Functionality to decrease country's funds
     *
     */
}

void Army::Advance(){
    std::cout<<"ADVANCE Troops!/n";
    ArmyIterator *itGround = groundUnit->createIterator();
    ArmyIterator *itAir = airUnit->createIterator();
    ArmyIterator *itMedic = medicUnit->createIterator();

    while (itGround->hasNext())
    {
        // itGround->current()->Advance(); // add Advance to Person classes
        itGround->increment();
    }

    while (itAir->hasNext())
    {
        // itAir->current()->Advance(); // add Advance to Person classes
        itAir->increment();
    }
    std::cout << "MEDICS move forward!\n";
    while (itMedic->hasNext())
    {
        // itMedic->current()->Advance(); // add Advance to Person classes
        itMedic->increment();
    }
}

/**
 * @brief All units retreat
 *
 */
void Army::Retreat()
{
    std::cout << "Retreating all troops\n";
    // Code here
    ArmyIterator *itGround = groundUnit->createIterator();
    ArmyIterator *itAir = airUnit->createIterator();
    ArmyIterator *itMedic = medicUnit->createIterator();

    while (itGround->hasNext())
    {
        itGround->current()->Retreat();
        itGround->increment();
    }

    while (itAir->hasNext())
    {
        itAir->current()->Retreat();
        itAir->increment();
    }
    std::cout << "MEDICS prepare the morphine!\n";
    while (itMedic->hasNext())
    {
        itMedic->current()->Retreat();
        itMedic->increment();
    }
}

/**
 * @brief Country signs a treaty and Army surrenders
 * 
 */
void Army::Surrender(){
    std::cout<<"'Wave the white flag'\n";
    ArmyIterator *itGround = groundUnit->createIterator();
    ArmyIterator *itAir = airUnit->createIterator();
    ArmyIterator *itMedic = medicUnit->createIterator();

    while (itGround->hasNext())
    {
        // itGround->current()->Attack(); // Add surrender to Person Classes
        itGround->increment();
    }

    while (itAir->hasNext())
    {
        // itAir->current()->Attack(); // Add surrender to Person Classes
        itAir->increment();
    }

    while (itMedic->hasNext())
    {
        // itMedic->current()->Attack(); // Add surrender to Person Classes
        itMedic->increment();
    }
}

/**
 * @brief
 *
 */
void Army::update()
{
    // Observer code here
}