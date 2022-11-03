/**
 * @file Army.cpp
 * @brief Army object which the Country aggregates from to create and utilise Army's functions
 * @version 4.21
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Army.h"
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
#include "../Country/Country.h"

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

/**
 * @brief Construct a new Army:: Army object
 *  Instantiate all units
 *  Using populateUnit() to populate all Units
 */
Army::Army(std::string name, int numOfSoldiers, int numOfMedics, int numOfPilots)
{
    countryName = name;
    MedicUnit *mUnit = new MedicUnit(name);
    medicUnit = mUnit;
    GroundUnit *gUnit = new GroundUnit(name);
    groundUnit = gUnit;
    AirUnit *aUnit = new AirUnit(name);
    airUnit = aUnit;
    fAttack = false;
    // battle art for army summary
    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);

    std::string filepath = current_working_dir + "/ArmyHierarchy/Soldier.txt";

    std::string line = "";
    std::ifstream inFile;
    inFile.open(filepath);
    std::cout << std::endl;

    int iCount = 0;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            iCount++;

            if (iCount == 6)
            {
                std::cout << line + "\t•Breakdown of the troops from " << countryName << ":\n";
                ;
            }
            else if (iCount == 7)
            {
                std::cout << line + "\t\t-Ground Units: " << numOfSoldiers << "\n";
            }
            else if (iCount == 8)
            {
                std::cout << line + "\t\t-Medic Units: " << numOfMedics << "\n";
            }
            else if (iCount == 9)
            {
                std::cout << line + "\t\t-Air Units: " << numOfPilots << "\n";
            }
            else
            {
                std::cout << line << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Failed to load Soldier.txt" << std::endl;
    }

    inFile.close();
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
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
void Army::populateUnit(int numOfSoldiers, int numOfMedics, int numOfPilots)
{
    groundUnit->populateUnit(numOfSoldiers);
    medicUnit->populateUnit(numOfMedics);
    airUnit->populateUnit(numOfPilots);
}

/**
 * @brief All units and Soldiers attack
 *
 * @return cout statement from units attack method
 */
int Army::Attack()
{
    ArmyIterator *itGround = groundUnit->createIterator();
    ArmyIterator *itAir = airUnit->createIterator();

    if(!fAttack){
        std::cout << countryName << "'s soldiers and medics have been transported to the frontlines for battle.\n";
        std::cout << countryName << "'s Air Units are incoming.\n";
        fAttack = true;
    }

    int power = 0;
    while (itGround->hasNext())
    {
        power += itGround->current()->getWeapon()->fire();
        itGround->increment();
    }
    while (itAir->hasNext())
    {
        power += itAir->current()->getWeapon()->fire();
        itAir->increment();
    }
    delete itGround;
    delete itAir;
    return power;
}

/**
 * @brief calculate total healing power of medics
 * 
 * @return int total healing power of medics
 */
int Army::Defend()
{
    
    int defense = 0;
    ArmyIterator* itMedicUnit = medicUnit->createIterator();

    while(itMedicUnit->hasNext()){
        defense += itMedicUnit->current()->heal();
        itMedicUnit->increment();
    }

    std::cout << "The medics of " << this->countryName << " healed " << defense / 100 << " soldiers on the battlefield.\n";
    delete itMedicUnit;
    return defense;
}

/**
 * @brief Army advances position
 * Function to call each person's Advance function
 */
void Army::Advance()
{
    std::cout << "ADVANCE Troops!/n";
}

/**
 * @brief All units retreat
 * Calling all person's retreat function
 */
void Army::Retreat()
{
    std::cout << countryName << " pulls back all troops\n";
}

/**
 * @brief Country signs a treaty and Army surrenders
 * Calls each person's Surrender function
 */
void Army::Surrender(Country *c)
{
    // battle art for army summary

    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);

    std::string filepath = current_working_dir + "/ArmyHierarchy/WhiteFlag.txt";

    std::string line = "";
    std::ifstream inFile;
    inFile.open(filepath);
    std::cout << std::endl;

    int iCount = 0;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            iCount++;

            if (iCount == 5)
            {
                std::cout << line << "\t\t" << countryName << " waves the white flag and surrenders!\n";
            }
            else if (iCount == 6)
            {
                std::cout << line << "\t\t" << c->getName() << " has won the battle!\n";
            }
            else
            {
                std::cout << line << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Failed to load Soldier.txt" << std::endl;
    }

    inFile.close();

    
}

/**
 * @brief Removes soldiers either from air unit or ground unit
 *
 * @param damage Number of soldiers to be removed
 */
void Army::RemoveSoldiers(int damage)
{

    int airUnitSize = airUnit->getSize();
    int groundUnitSize = groundUnit->getSize();
    
    int num = std::rand() % 2;
    
    // when artillery/nuke is used to kill stuff
    
    if (damage > 24000)
    {
        if (airUnitSize == 0)
        {
            num = 1;
        }
        else if (groundUnitSize == 0)
        {
            num = 0;
        }
    }

    if (num == 0)
    {
        for (int i = 0; i < damage / 10; i++)
            airUnit->remove();
    }
    else
    {
        for (int i = 0; i < damage; i++)
            groundUnit->remove();
    }
    if (damage >= 0)
    {
        if (num == 0)
        {
            if (airUnit->getSize() < damage / 10)
            {
                if (airUnitSize == 0)
                {
                    std::cout << "There were no casualties to the air unit in this attack.\n";
                }
                else
                {
                    std::cout << airUnitSize - airUnit->getSize() << " soldiers from " << countryName << " were killed in battle.\n";
                }
            }
            else
                std::cout << damage / 10 << " soldiers from " << countryName << " were killed in battle.\n";
        }
        else
        {
            if (groundUnit->getSize() < damage)
            {
                if (groundUnitSize == 0)
                {
                    std::cout << "There were no casualties to the ground units in this attack.\n";
                }
                else
                {
                    std::cout << groundUnitSize - groundUnit->getSize() << " soldiers from " << countryName << " were killed in battle.\n";
                }
            }
            else
                std::cout << damage << " soldiers from " << countryName << " were killed in battle.\n";
        }
    }
    else
    {
        Retreat();
    }
    std::cout << "AirUnit size: " << airUnit->getSize() << "\n";
    std::cout << "GroundUnit size: " << groundUnit->getSize() << "\n";
}
 
/**
 * @brief returns name of Country this army belongs to
 * 
 * @return std::string countryName
 */
std::string Army::getName()
{
    return countryName;
}

/**
 * @brief get thenumber of soldiers in the army
 * 
 * @return int number of soldiers
 */
int Army::getNumOfSoldiers()
{
    return groundUnit->getSize() + airUnit->getSize();
}