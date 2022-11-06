/**
 * @file Airspace.cpp
 * @brief Simulating the battle of Pearl Habor
 * @version 1.0
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Airspace.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "../Country/Alliance.h"
#include "../Country/Artillery.h"
#include "../Country/Nuke.h"

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace std;

Airspace::Airspace(){}

Airspace::~Airspace(){}

void Airspace::add(Country *force)
{
    countries.push_back(force);
}

void Airspace::remove(Country *force)
{
    countries.pop_back();
}

/**
 * @brief The beginning of the war
 * 
 * Describes the war
 * 
 */
void Airspace::printBattleSummary() 
{
    string summary = "On the morning of December 7, 1941, Japan attacked the US naval base at Pearl Harbor, Hawaii.\n"
                     "The surprise attack by some 350 Japanese aircraft sunk or badly damaged eighteen US naval vessels, including eight battleships, destroyed or damaged 300 US aircraft, and killed 2,403 men.\n"
                     "Across the nation, Americans were stunned, shocked, and angered.\n"
                     "The attack turned US public opinion in favor of entering the Second World War.\n"
                     "The United States declared war on Japan on December 8, 1941.\n"
                     "Japanese allies, Germany and Italy, declared war on the United States on December 11. The United States responded in kind, and therefore entered World War II.";
                            

    string battleDate = "Date: December 7, 1941";

    string battleNickName = "Nickname: Be all and end all";

    string Objective = "Objective: Hold off American forces";

    string Place = "Location: Pearl Harbor, Hawaii & Hiroshima, Japan";

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

    this_thread::sleep_for(chrono::milliseconds(1000));

    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    string current_working_dir(buff);

    string filepath = current_working_dir + "/WarTheater/PearlHarbourMap.txt";

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
        cout << "Failed to load PearlHarbourMap.txt" << endl;
    }

    inFile.close();

    this_thread::sleep_for(chrono::milliseconds(3000));

    cout << endl;

    cout << summary << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
}

/**
 * @brief Function to load the ASCII text to the terminal
 * 
 */
void Airspace::loadBattleArt()
{
    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    string current_working_dir(buff);

    string filepath = current_working_dir + "/WarTheater/PearlHarbour.txt";  /// *** I changed the filepath, file will be called pearlharbour

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
        cout << "Failed to load PearlHarbour.txt" << endl;
    }

    inFile.close();
}

/**
 * @brief Main Warloop for the battle
 * 
 */
void Airspace::warLoop()
{
    cout << endl;
    int ModeChoice = -1;
    while (ModeChoice != 1 && ModeChoice != 2)
    {
        cout << "Would you like to play:\n\t1. Real Mode\n\t2. Design Mode\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> ModeChoice;

        if (ModeChoice != 1 && ModeChoice != 2)
        {
            cout << "Please enter a valid choice (1) or (2) to proceed!" << endl;
        }
    }

    cout << endl;

    if (ModeChoice == 1)
    {
        // Countries: Japan, America
        Country *Japan = new Country("Japan", 150000);
        Country *America = new Country("America", 200000);

        bool LaunchedArtillery = false;

        while(true)
        {
            // AmericaCopy = nullptr;
            if (Japan->getNumOfSoldiers() <= 3000 && !LaunchedArtillery)
            {
                America = new Nuke(America);
                LaunchedArtillery = true;
                cout << "America is angered by the Japanese bombings on Pearl Harbour..." << endl;
                cout << "Japan doesn't know what's about to hit them..." << endl << endl;
            }

            America->Attack(Japan);
            America = America->getCountry();
            cout << endl;
            // Check for surrender
            if (Japan->surrender(America))
            {
                break;
            }
            Japan->Attack(America);

            if (America->surrender(Japan))
            {
                break;
            }

            cout << endl;
        }

        America = America->getCountry();
        delete Japan;
        delete America;
    }
    else if(ModeChoice == 2)
    {
        // array of ally countries
        vector<string> allies = {"Germany", "Italy", "Japan", "France", "Great Britain", "The United States", "The Soviet Union"};

        vector<double> allyFunds =
            {
                66000, // Germany 
                30000, // Italy
                35000, // Japan
                40000, // France
                50000, // Great Britain
                65000, // United States
                62000  // Soviet Union
            };

        int iCount1 = 0;
        int iCount2 = 0;
        string c1, c2;

        //f1 = 200000
        //f2 = 180000
        double f1, f2;

        std::cout << "Enter the name of country 1: ";
        cin >> c1;
        std::cout<<endl;
        std::cout << "Enter the amount of funds for " << c1 << " [Range from 100000 to 300000]: ";
        cin >> f1;
        while(f1 < 100000 || f1 > 300000)
        {
            cout << "Please enter a valid amount of funds for " << c1 <<". [Range from 100000 to 300000]: ";
            cin >> f1;
            cout << endl;
        }

        std::cout << "Enter the name of country 2: ";
        cin >> c2;
        std::cout<<endl;
        std::cout << "Enter the amount of funds for " << c2 << ". [Range from 100000 to 300000]: ";
        cin >> f2;

        while(f2 < 100000 || f2 > 300000)
        {
            cout << "Please enter a valid amount of funds for " << c2 << " [Range from 100000 to 300000]: ";
            cin >> f2;
            cout << endl;
        }
        
        std::cout<<endl;
        
        
        Country *country1 = new Country(c1, f1);
        Country *country2 = new Country(c2, f2);

        Country *ally1 = nullptr;
        Country *ally2 = nullptr;

        int a = 0; // input variable for if they want to form an alliance

        //number of soldiers per country
        int country1Soldiers = country1->getNumOfSoldiers();
        int country2Soldiers = country2->getNumOfSoldiers();

        // main function loop
        while(!country1->surrender(country2) && !country2->surrender(country1))
        {

            if(country1->getNumOfSoldiers() < country1Soldiers/2 && iCount1 == 0)
            {
                do
                {
                    cout << "Would you like " << c1 << " to form an alliance with one of these countries: \n";
                    std::cout << "\t0. None"<<endl;
                    int iNumber = 1;
                    for(string x : allies)
                    {
                      cout<<"\t"<<iNumber<< ". "<<x<<endl;
                      iNumber++;
                    }

                   cout << "\nEnter a number to form your alliance: ";
                   cin >> a;
                   if(a < 0 || a > allies.size())  
                    { 
                       cout << "Please enter a valid option!\n";
                    }
                    else if(a == 0)
                    {
                        cout << c1 << " has chosen not to form any alliances." << endl;
                        break;
                    } 
                    else 
                    { 
                      break; 
                    }
                    
                }while(true);
                
                if(a != 0)
                {
                    ally1 = new Country(allies[a-1], allyFunds[a - 1]);
                    Alliance *ally = new Alliance();
                    ally->addAlliance(ally1);
                    country1->joinAlliance(ally);
                    country1->addFunds(allyFunds[a - 1]);

                    allies.erase(allies.begin() + (a-1));
                    allyFunds.erase(allyFunds.begin() + (a-1));
                }
                iCount1++;
            }
            else if (country2->getNumOfSoldiers() < country2Soldiers/2 && iCount2 == 0)
            { 
                do 
                {
                    cout << "Would you like " << c2 << " to form an alliance with one of these countries: \n";
                    std::cout << "\t0. None" << endl;
                    int iNumber = 1;
                 
                    for (string x : allies)
                    {
                        cout<<"\t"<<iNumber<< ". "<<x<<endl;
                        iNumber++;
                    }

                   cout << "\nEnter a number to form your alliance: ";
                   cin >> a;  
                   
                   if(a < 0 || a > allies.size())  
                    { 
                        cout << "Please enter a valid option!\n";
                    }
                    else if(a == 0)
                    {
                        cout << c2 << " has chosen not to form any alliances." << endl;
                        break;
                    }
                    else 
                    { 
                       break; 
                    } 
                   
                }while(true);
                
                if(a != 0)
                {                    
                    ally2 = new Country(allies[a - 1], allyFunds[a - 1]);
                    Alliance *ally = new Alliance();
                    ally->addAlliance(ally1);
                    country2->joinAlliance(new Alliance());
                    country2->addFunds(allyFunds[a - 1]);

                    allies.erase(allies.begin() + (a-1));
                    allyFunds.erase(allyFunds.begin() + (a-1));
                }
                iCount2++;
            }
            // WMD, only asks if Ally option has been asked already
            if(country1->getNumOfSoldiers() < country1Soldiers/3 && iCount1 == 1)
            {
                char ans = 'n';
                int iWMD = -1;
                do 
                {
                    cout << "\nWould you like " << country1->getName() << " to deploy a weapon of mass destruction on " <<c2<< "? [Y/N]: ";
                    cin >> ans; 
                    if(ans!='Y' && ans!='y' && ans!='n' && ans!='N') 
                    { 
                        cout<<"Please enter a valid option!\n";
                    }  
                   else
                   { 
                        break;
                   }

                }while(true);
                
                if(ans == 'Y' || ans == 'y')
                {
                    do 
                    {
                       cout << "Please select a weapon of mass destruction:\n";
                       cout << "\t1. Nuke\n";
                       cout << "\t2. Artillery strike\n";
                       cout << "\nEnter your choice: ";

                       cin >> iWMD; 
                       if(iWMD != 1 && iWMD != 2) 
                       { 
                          cout << "Please enter a valid option!\n";
                       }
                       else 
                       { 
                          break;
                       }

                    }while(true);
                    if(iWMD == 1)
                    {
                        country1 = new Nuke(country1);
                    }
                    else if(iWMD == 2)
                    {
                        country1 = new Artillery(country1);
                    }
                }
                else
                {
                    cout << c1 << " has chosen not to deploy a weapon of mass destruction" << endl;
                }
                iCount1++;
            }
            else if(country2->getNumOfSoldiers() < country2Soldiers/3 && iCount2 == 1)
            {
                char ans = 'n';
                int iWMD = -1;
                    
                do 
                {
                    cout << "\nWould you like " << country2->getName() << " to deploy a weapon of mass destruction on " <<c1<< "? [Y/N]: ";
                    cin >> ans; 
                    if(ans!='Y' && ans!='y' && ans!='n' && ans!='N') 
                    { 
                       cout<<"Please enter a valid option!\n";
                    }  
                   else
                   { 
                       break;
                   }
                   
                }while(true);
                if(ans == 'Y' || ans == 'y')
                {
                    do 
                    {
                        cout << "Please select a weapon of mass destruction:\n";
                        cout << "\t1. Nuke\n";
                        cout << "\t2. Artillery strike\n";
                        cout << "\nEnter your choice: ";
                        
                        cin >> iWMD; 
                        if(iWMD!=1 && iWMD!=2) 
                        { 
                            cout<<"Please enter a valid option!\n";
                        } 
                        else 
                        { 
                            break;
                        }
                    }
                    while(true);
                    {
                        if (iWMD == 1)
                        {
                            // NUKE
                            country2 = new Nuke(country2);
                        }
                        else if (iWMD == 2)
                        {
                            // ARTILLERY STRIKE
                            country2 = new Artillery(country2);
                        }
                    }
                }
                else
                {
                    cout<<c2<<" has chosen not to deploy a weapon of mass destruction."<<endl;
                }
                iCount2++;
            }
            
            country2->Attack(country1);
            cout << endl;
            country1->Attack(country2);
            cout << endl;
            if(iCount1 == 2)
            {
                country1 = country1->getCountry();
                iCount1++;
            }
            else if(iCount2 == 2)
            {
                country2 = country2->getCountry();
                iCount2++;
            }
            
        }

        cout << "BATTLE SUMMARY: " << endl;
        cout << "Total number of fallen soldiers for " << country1->getName();

        cout << ": " << int(f1 / 10 + f1 / 50) - country1->getNumOfSoldiers() << "\n\n";

        cout << "Total number of fallen soldiers for " << country2->getName();
        cout << ": " << int(f2 / 10 + f2 / 50) - country2->getNumOfSoldiers() << "\n\n";

        country1 = country1->getCountry();
        country2 = country2->getCountry();
        delete country1;
        delete country2;
        if(ally1 != nullptr)
        {
            delete ally1;
        }
        if(ally2 != nullptr)
        {
            delete ally2;
        }
    }
}