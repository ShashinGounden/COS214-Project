#include "Army.h"

/**
 * @brief Construct a new Army:: Army object
 * 
 */
Army::Army(std::string cName) : Country(cName){
    std::cout<<"Creating Army\n";
    createAirUnit();
    createGroundUnit();
    createMedicUnit();
}

/**
 * @brief Destroy the Army:: Army object
 * 
 */
Army::~Army(){
    delete medicUnit;
    delete groundUnit;
    delete airUnit;
}

/**
 * @brief Creation of All Units
 * 
 */
void Army::createMedicUnit(){
    MedicUnit *unit = new MedicUnit();
    medicUnit = unit;
}

void Army::createGroundUnit(){
    GroundUnit *unit = new GroundUnit();
    groundUnit = unit;
}

void Army::createAirUnit(){
    AirUnit *unit = new AirUnit();
    airUnit = unit;
}

/**
 * @brief All units and Soldiers attack
 * 
 * @return cout statement from units attack method
 */
void Army::attack(){
    std::cout<<"All soldiers ATTACK!\n";
    ArmyIterator* itGround = groundUnit->createIterator();
    ArmyIterator* itAir = airUnit->createIterator();
    ArmyIterator* itMedic = medicUnit->createIterator();

    while(itGround->hasNext()){
        
        itGround->current()->attack();
        itGround->current()->getID();
        itGround->increment();
    }

    while(itAir->hasNext()){
        itAir->current()->attack();
        itAir->increment();
    }
    std::cout<<"MEDICS prepare the morphine!\n";
    while(itMedic->hasNext()){
        itMedic->current()->attack();
        itMedic->increment();
    }
}

/**
 * @brief All units retreat
 * 
 */
void Army::retreat(){
    std::cout<<"Retreating all troops\n";
    // Code here
}

/**
 * @brief 
 * 
 */
void Army::update(){
    // Observer code here
}