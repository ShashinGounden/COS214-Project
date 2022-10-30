#include "Airspace.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
using namespace std;

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

Airspace::Airspace()
{
}

Airspace::~Airspace()
{
}

void Airspace::add(Country *force)
{
    countries.push_back(force);
}

void Airspace::remove(Country *force)
{
    countries.erase(std::remove(countries.begin(), countries.end(), force), countries.end());
}

void Airspace::warLoop()
{
    cout << "BEGIN Sea battle War Loop" << endl;
    
}

void Airspace::printBattleSummary()
{
    string summary = "The D-Day operation of June 6, 1944 brought together the land, air and sea forces of the allied armies in what became known as the largest invasion force in human history.\n"
                     "The operation, given the codename OVERLORD, delivered five naval assault divisions to the beaches of Normandy, France.\n"
                     "The invasion force included 7,000 ships and landing craft manned by over 195,000 naval personnel from eight allied countries.\n"
                     "Almost 133,000 troops from England, Canada and the United States landed on D-Day.\n"
                     "Casualties from the three countries during the landing numbered 10,300. By June 30th, over 850,000 men, 148,000 vehicles, and 570,000 tons of supplies had landed on the Normandy shores.\n"
                     "Fighting by the brave soldiers, sailors and airmen of the allied forces western front, and Russian forces on the eastern front, led to the defeat of German Nazi forces.";

    string battleDate = "Date: June 6, 1944";

    string battleNickName = "Nickname: Operation Overlord, D-Day";

    string Objective = "Objective: Successfully invade German territories";

    // displays battle nickname with type writer effect
    for (const auto c : battleNickName)
    {
        cout << c << flush;
     //   this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;

    for (const auto c : battleDate)
    {
        cout << c << flush;
     //   this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;

    for (const auto c : Objective)
    {
        cout << c << flush;
    //    this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;
    cout << endl;

    cout << summary << endl;
}

void Airspace::loadBattleArt()
{
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir( buff, FILENAME_MAX );
    string current_working_dir(buff);

    string filepath = current_working_dir + "/WarTheater/Normandy.txt";

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
        cout << "Failed to load Normandy.txt" << endl;
    }

    inFile.close();
}
