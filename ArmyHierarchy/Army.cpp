#include "Army.h"
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
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
    MedicUnit *mUnit = new MedicUnit();
    medicUnit = mUnit;
    GroundUnit *gUnit = new GroundUnit();
    groundUnit = gUnit;
    AirUnit *aUnit = new AirUnit();
    airUnit = aUnit;
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

int Army::Defend()
{
    int defense = medicUnit->getHealPower();
    return defense;
}

/**
 * @brief Army advances position
 * Function to call each person's Advance function
 */
void Army::Advance()
{
    std::cout << "ADVANCE Troops!/n";
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
    delete itGround;
    delete itAir;
    delete itMedic;
}

/**
 * @brief All units retreat
 * Calling all person's retreat function
 */
void Army::Retreat()
{
    std::cout << countryName << " pulls back all troops\n";
    // Code here
}

/**
 * @brief Country signs a treaty and Army surrenders
 * Calls each person's Surrender function
 */
void Army::Surrender(Country *c)
{
    // battle art for army summary
    std::cout << " waves the white flag and surrenders!\n";

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

            std::cout << line << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to load Soldier.txt" << std::endl;
    }

    inFile.close();

    // how to get france's name? can only get Germany by using countries name var
    std::cout << c->getName() << " has won the battle!"
              << "\n";
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
    if (num == 0)
    {
        for (int i = 0; i < damage / 1000; i++)
            airUnit->remove();
    }
    else
    {
        for (int i = 0; i < damage / 100; i++)
            groundUnit->remove();
    }
    if (damage >= 0)
    {
        if (num == 0)
        {
            if (airUnit->getSize() < damage / 100)
            {
                std::cout << airUnitSize - airUnit->getSize() << " soldiers from " << countryName << " were killed in battle.\n";
            }
            else
                std::cout << damage / 100 << " soldiers from " << countryName << " were killed in battle.\n";
        }else{
            if (groundUnit->getSize() < damage / 100)
            {
                std::cout << groundUnitSize - groundUnit->getSize() << " soldiers from " << countryName << " were killed in battle.\n";
            }
            else
                std::cout << damage / 100 << " soldiers from " << countryName << " were killed in battle.\n";
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
 * @brief
 *
 */
void Army::update()
{
    // Observer code here
}

std::string Army::getName()
{
    return countryName;
}