#include "Sea.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

Sea::Sea()
{
}

Sea::~Sea()
{
}

void Sea::add(Country *force)
{
    countries.push_back(force);
}

void Sea::remove(Country *force)
{
    countries.erase(std::remove(countries.begin(), countries.end(), force), countries.end());
}

void Sea::printBattleSummary()
{
    string summary = "In 1940, nearly 300,000 Allied troops were stranded on the beach at Dunkirk, France. \n"
                     "Troops were caught between the German advance and the English Channel.\n"
                     "They were so close to England that the desperate soldiers could almost see their loved ones back home.\n"
                     "An evacuation was planned for the British troops using Royal Navy ships. But instead these men endured a horrific nine-day siege.\n"
                     "They became sitting ducks as Nazi airplanes strafed and bombed the beach and the rescue ships filled with thousands of men.";

    string battleDate = "Date: 26 May 1940 - 4 June 1940";

    string battleNickName = "Nickname: Operation Dynamo";

    string Objective = "Objective: Rescue of over 300,000 Allied soldiers";

    // displays battle nickname with type writer effect
    for (const auto c : battleNickName)
    {
        cout << c << flush;
        //    this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;

    for (const auto c : battleDate)
    {
        cout << c << flush;
        //  this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;

    for (const auto c : Objective)
    {
        cout << c << flush;
        //  this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;
    cout << endl;

    cout << summary << endl;
}

void Sea::loadBattleArt()
{

    string filepath = "/mnt/c/Users/jorda/OneDrive/1.UniversityOfPRETORIA/Second Year - 2022/1.COS214/Practicals/Prac5_and_Project/COS214-Project/WarTheater/Dunkirk.txt";
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

void Sea::warLoop()
{
    cout << endl;
    int ModeChoice;
    while (ModeChoice != 1 && ModeChoice != 2)
    {
        cout << "Would you like to play:\n1. Real Mode\n2. Design Mode\n";
        cout << "Enter your choice: ";
        cin >> ModeChoice;

        if (ModeChoice != 1 && ModeChoice != 2)
        {
            cout << "Please enter a valid choice (1) or (2) to proceed!" << endl;
        }
    }

    if (ModeChoice == 1)
    {
        // Countries: Germany, France
        Country *Germany = new Country("Germany", 100000);
        Country *France = new Country("France", 200000);

        while (!Germany->surrender() && !France->surrender())
        {
            France->Attack(Germany);
            cout << endl;
            //// this_thread::sleep_for(chrono::milliseconds(300));
            Germany->Attack(France);
            cout << endl;
            // this_thread::sleep_for(chrono::milliseconds(300));
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
            //// this_thread::sleep_for(chrono::milliseconds(300));
            Germany->Attack(France);
            cout << endl;
            // this_thread::sleep_for(chrono::milliseconds(300));

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
