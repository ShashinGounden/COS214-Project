#include "Artillery.h"
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

Artillery::Artillery(Country *c) : WMD(c)
{
    //   std::cout << owner->getName() << " has prepared heavy artillery!\n";
}

Artillery::~Artillery()
{
}

void Artillery::wmd()
{
    ArtilleryStrike();
}

/**
 * @brief
 *
 */
void Artillery::Attack(Country *c)
{
    if (owner != NULL)
    {

        wmd();
        c->takeDamage(1300000);
        owner->addFunds(-24000);

        owner->Attack(c);
    }
}

void Artillery::takeDamage(int g)
{
    if (owner != NULL)
        owner->takeDamage(g);
}
/**
 * @brief Artillery strike for the country
 *
 * Will cost the country a specific amount of funds to be able to execute a strike
 */
void Artillery::ArtilleryStrike()
{
    std::cout << owner->getName() << " has launched artillery strike!\n";

    // Add text art here - @ShashinGounden
    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    string current_working_dir(buff);
    string filepath = current_working_dir + "/Country/Artillery.txt";
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
        cout << "Failed to load Artil.txt" << endl;
    }

    inFile.close();
}