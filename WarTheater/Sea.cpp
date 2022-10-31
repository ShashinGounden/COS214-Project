#include "Sea.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <iostream>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace std;

/**
 * @author Shashin Gounden
 * @brief Constructor for Sea war theater
 * Creates a Sea war Theater
 */

Sea::Sea()
{
}

/**
 * @author Shashin Gounden
 * @brief Destructor for Sea war theater
 * Deallocates memory after a War Theater is no longer used
 */

Sea::~Sea()
{
}

/**
 * @author Shashin Gounden
 * @brief Adds a country to the war theater
 * Adds country to a war theater by adding it to a vector using the push_back() method in the vector STL
 */

void Sea::add(Country *force)
{
    countries.push_back(force);
}

/**
 * @author Shashin Gounden
 * @brief Removes a country from the war theater
 * Removes a country from the war theater by removing it from a vector using the erase() method in the vector STL
 */
void Sea::remove(Country *force)
{
    countries.erase(std::remove(countries.begin(), countries.end(), force), countries.end());
}

/**
 * @author Shashin Gounden
 * @brief Displays a summary of the Battle of Dunkirk using a typewriter effect and also using ASCII art as the GUI component
 * ASCII art is loaded from the relevant text files
 */
void Sea::printBattleSummary()
{
    string summary = "In 1940, nearly 300,000 Allied troops were stranded on the beach at Dunkirk, France. \n"
                     "Troops were caught between the German advance and the English Channel.\n"
                     "They were so close to England that the desperate soldiers could almost see their loved ones back home.\n"
                     "An evacuation was planned for the British troops using Royal Navy ships. But instead these men endured a horrific nine-day siege.\n"
                     "They became sitting ducks as Nazi airplanes strafed and bombed the beach and the rescue ships filled with thousands of men.";

    string battleDate = "Date: 26 May 1940 - 4 June 1940";

    string battleNickName = "Nickname: Operation Dynamo";

    string Objective = "Objective: Defend against attack of German soldiers";

    string Place = "Location: ";

    // displays battle nickname with type writer effect
    for (const auto c : battleNickName)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;

    for (const auto c : battleDate)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;

    for (const auto c : Objective)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;

    for (const auto c : Place)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir( buff, FILENAME_MAX );
    string current_working_dir(buff);

    string filepath = current_working_dir + "/WarTheater/DunkirkMap.txt";

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
        cout << "Failed to load DunkirkMap.txt" << endl;
    }

    inFile.close();

    this_thread::sleep_for(chrono::milliseconds(3000));

    cout << endl;

    cout << summary << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
}

/**
 * @author Shashin Gounden
 * @brief Loads the ASCII art from a text file and displays it before the simulation begins
 * ASCII art is loaded from the relevant text files
 */

void Sea::loadBattleArt()
{
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir( buff, FILENAME_MAX );
    string current_working_dir(buff);

    string filepath = current_working_dir + "/WarTheater/Dunkirk.txt";

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
        cout << "Failed to load Dunkirk.txt" << endl;
    }

    inFile.close();
}

/**
 * @author Shashin Gounden
 * @brief The war loop for the battle of dunkirk which gives the user a choice between real and design mode
 */

void Sea::warLoop()
{
    cout << endl;
    int ModeChoice = -1;
    while (ModeChoice != 1 && ModeChoice != 2)
    {
        cout << "Would you like to play:\n\t1. Real Mode\n\t2. Design Mode\n";
        cout<<endl;
        cout << "Enter your choice: ";
        cin >> ModeChoice;

        if (ModeChoice != 1 && ModeChoice != 2)
        {
            cout << "Please enter a valid choice (1) or (2) to proceed!" << endl;
        }
    }

    cout<<endl;

    if (ModeChoice == 1)
    {
        // Countries: Germany, France
        Country *Germany = new Country("Germany", 100000);
        Country *France = new Country("France", 200000);

        while (!Germany->surrender() && !France->surrender())
        {
            France->Attack(Germany);
            cout << endl;
            Germany->Attack(France);
            cout << endl;
        }

        delete Germany;
        delete France;
    }
    else if (ModeChoice == 2)
    {
        // Countries: Germany, France
        Country *Germany = new Country("Germany", 100000);
        Country *France = new Country("France", 200000);

        while (!Germany->surrender() && !France->surrender())
        {
            France->Attack(Germany);
            cout << endl;
            Germany->Attack(France);
            cout << endl;
        }

        delete Germany;
        delete France;






        // Design Mode

        //What are we going to change

        //begin loop
        //pick countries names (2)
        //pick countries funds (2)

       //display units from funds entered

        //want to form alliance when funds reach half, the first time

        //want to add more soldiers?

       //if other countries about to die, give  a choice to finish them with a WMD


       //end of loop, give user a choice


    }
}
