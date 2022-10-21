#include "Army.h"

/**
 * @brief Construct a new Army:: Army object
 *  Instantiate all units
 *  Using populateUnit() to populate all Units
 */
Army::Army(int numOfSoldiers, int numOfMedics, int numOfPilots)
{
    std::cout << "Creating Army\n";
    MedicUnit *mUnit = new MedicUnit();
    medicUnit = mUnit;
    GroundUnit *gUnit = new GroundUnit();
    groundUnit = gUnit;
    AirUnit *aUnit = new AirUnit();
    airUnit = aUnit;

    populateUnit(numOfSoldiers, numOfMedics, numOfPilots);
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
 * @brief using each units populateUnit function to populate each unit
 * with the input parameters amount
 * 
 * @param numOfSoldiers 
 * @param numOfMedics 
 * @param numOfPilots 
 */
void Army::populateUnit(int numOfSoldiers, int numOfMedics, int numOfPilots){
    groundUnit->populateUnit(numOfSoldiers);
    medicUnit->populateUnit(numOfMedics);
    airUnit->populateUnit(numOfPilots);
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
        // itAir->current()->takeDamage(20);
        itAir->increment();
    }
    std::cout << "MEDICS prepare the morphine!\n";
    while (itMedic->hasNext())
    {
        itMedic->current()->Attack();
        // itMedic->current()->heal(Person*, int);
        itMedic->increment();
    }

    /**
     * @brief Add Functionality to decrease country's funds
     *
     */
}

/**
 * @brief Army advances position
 * Function to call each person's Advance function
 */
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
 * Calling all person's retreat function
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
 * Calls each person's Surrender function
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