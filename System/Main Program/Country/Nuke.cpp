#include "Nuke.h"
#include <string>
#include <fstream>
using namespace std;

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

/**
 * @brief Construct a new Nuke:: Nuke object
 * 
 * @param c 
 */
Nuke::Nuke(Country *c) : WMD(c)
{
}

/**
 * @brief Destroy the Nuke:: Nuke object
 * 
 */
Nuke::~Nuke()
{
}

/**
 * @brief deploys nuke
 * 
 */
void Nuke::wmd()
{
    deployNuke();
}

/**
 * @brief fires a weapon of mass destruction and then an attack with troops
 * 
 * @param c enemy country
 */
void Nuke::Attack(Country *c)
{
    if (owner != NULL)
    {
        wmd();
        c->takeDamage(3000000);
        owner->addFunds(-25000);
        owner->Attack(c);
    }
}

/**
 * @brief receives damage from an enemy country
 * 
 * @param d damage value
 */
void Nuke::takeDamage(int d)
{
    if (owner != NULL)
        owner->takeDamage(d);
}

/**
 * @brief country deploys nuke on opposing country
 *
 * Costs the country a certain amount of funds to be able to have a
 * nuke in its arsenal - Will cost more than a artillery strike
 */
void Nuke::deployNuke()
{
    std::cout << owner->getName() << " deploys nuke!\n";

    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    string current_working_dir(buff);
    string filepath = current_working_dir + "/Country/Nuke.txt";
    string line = "";
    ifstream inFile;
    inFile.open(filepath);
    cout << endl;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "Failed to load Nuke.txt" << endl;
    }

    inFile.close();
}