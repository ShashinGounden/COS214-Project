#include "Sea.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
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

    string battleDate = "Date: 26 May 1940 – 4 June 1940";

    string battleNickName = "Nickname: Operation Dynamo";

    string Objective = "Objective: Rescue of over 300,000 Allied soldiers";

    //displays battle nickname with type writer effect
    for (const auto c : battleNickName)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout<<endl;

    for (const auto c : battleDate)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout<<endl;

    for (const auto c : Objective)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout<<endl;
    cout<<endl;

    cout<<summary<<endl;
}

void Sea::loadBattleArt()
{
    //Need to change to the correct path according to folder structure
    string fileName = "/Users/shashingounden/Desktop/External Test/WarTheater/Dunkirk.txt";
    string line = "";
    ifstream inFile;
    inFile.open(fileName);
    cout<<endl;
    if (inFile.is_open())
    {
        while (getline(inFile,line))
        {
            cout<<line<<endl;
        }
    }
    else
    {
        cout<<"Failed to load Dunkirk.txt"<<endl;
    }

    inFile.close();
}

void Sea::warLoop()
{
    cout<<"BEGIN AirSpace WarLoop from here"<<endl;
}

