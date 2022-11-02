#include "Sea.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
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
        //    this_thread::sleep_for(chrono::milliseconds(200));
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
        // this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;

    for (const auto c : Place)
    {
        cout << c << flush;
        // this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;

    // this_thread::sleep_for(chrono::milliseconds(1000));

    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
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

    // this_thread::sleep_for(chrono::milliseconds(3000));

    cout << endl;

    cout << summary << endl;
    // this_thread::sleep_for(chrono::milliseconds(3000));
}

/**
 * @author Shashin Gounden
 * @brief Loads the ASCII art from a text file and displays it before the simulation begins
 * ASCII art is loaded from the relevant text files
 */

void Sea::loadBattleArt()
{
    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
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
        // Countries: Germany, France
        Country *Germany = new Country("Germany", 150000);
        Country *France = new Country("France", 200000);
        // Country* FranceCopy = France->clone();

        bool LaunchedArtillery = false;

        while (true)
        {
            // FranceCopy = nullptr;
            if (Germany->getNumOfSoldiers() <= 3000 && !LaunchedArtillery)
            {
                France = new Artillery(France);
                LaunchedArtillery = true;
            }

            France->Attack(Germany);
            France = France->getCountry();
            cout << endl;
            // Check for surrender
            if (Germany->surrender(France))
            {
                break;
            }
            Germany->Attack(France);

            if (France->surrender(Germany))
            {
                break;
            }

            cout << endl;
            // Checl
        }

        France = France->getCountry();
        delete Germany;
        delete France;
    }
    else if (ModeChoice == 2)
    {
        // array of ally countries
        vector<string> allies = {"Germany", "Italy", "Japan", "France", "Great Britain", "The United States", "The Soviet Union"};

        vector<double> allyFunds =
            {
                66000, // Germany - Nazi Scum
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
        std::cout << "Enter the amount of funds for country 1(Between 100000 and 300000): ";
        cin >> f1;
        while(f1 < 100000 || f1 > 300000)
        {
            cout << "Please enter a valid amount of funds for "<<c1<<": ";
            cin >> f1;
            cout << endl;
        }

        std::cout << "Enter the name of country 2: ";
        cin >> c2;
        std::cout<<endl;
        std::cout << "Enter the amount of funds for country 2(Between 100000 and 300000): ";
        cin >> f2;
        while(f2 < 100000 || f2 > 300000)
        {
            cout << "Please enter a valid amount of funds for "<<c2<<": ";
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
        while (!country1->surrender(country2) && !country2->surrender(country1))
        {

            if (country1->getNumOfSoldiers() < country1Soldiers/2 && iCount1 == 0)
            {
                do
                {
                        
                    cout << "Would you like " << c1 << " to form an alliance with one of these countries: \n";
                    std::cout << "\t0. None"<<endl;
                    int iNumber = 1;
                 
                    for (string x : allies)
                    {
                      cout<<"\t"<<iNumber<< ". "<<x<<endl;
                      iNumber++;
                    }

                   cout << "Enter the number referring to the country you want to add in: ";

                   cin >> a;
                   if(a<0 || a>allies.size())  
                    { 
                       cout<<"Please pick a valid option!\n";
                    } 

                    else 
                    { 
                      break; 
                    }
                    
                }while(true);
                
                if (a != 0)
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
                    std::cout << "\t0. None"<<endl;
                    int iNumber = 1;
                 
                    for (string x : allies)
                    {
                      cout<<"\t"<<iNumber<< ". "<<x<<endl;
                      iNumber++;
                    }

                   cout << "Enter the number referring to the country you want to add in: ";
                   cin >> a;  
                   
                   if(a<0 || a>allies.size())  
                    { 
                        cout<<"Please pick a valid option!\n";
                    } 

                    else 
                    { 
                       break; 
                    } 
                   
                }while(true);
                
                if (a != 0)
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
            if (country1->getNumOfSoldiers() < country1Soldiers/3 && iCount1 == 1)
            {
                char ans = 'n';
                int iWMD = -1;
                do 
                {
                    cout << "Would you like " << country1->getName() << " to deploy a weapon of mass destruction? [Y/N]: ";
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
                
                if (ans == 'Y' || ans == 'y')
                {
                    do 
                    {
                       cout << "Please select a weapon of mass destruction:\n";
                       cout << "1. Nuke\n";
                       cout << "2. Artillery strike\n";
                       cout << "Enter your choice: ";

                       cin >> iWMD; 
                       if(iWMD!=1 && iWMD!=2) 
                       { 
                          cout<<"Please enter a valid option!\n";
                       }
                        
                       else 
                       { 
                          break;
                       }

                    }while(true);
                    if (iWMD == 1)
                    {
                        country1 = new Nuke(country1);
                    }
                    else if (iWMD == 2)
                    {
                        // std::cout << country1->getName() << " has prepared heavy artillery!\n";
                        country1 = new Artillery(country1);
                    }
                }
                iCount1++;
            }
            else if (country2->getNumOfSoldiers() < country2Soldiers/3 && iCount2 == 1)
            {
                char ans = 'n';
                int iWMD = -1;
                    
                do 
                {
                    cout << "Would you like " << country2->getName() << " to deploy a weapon of mass destruction? [Y/N]: ";


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
                if (ans == 'Y' || ans == 'y')
                {
                    do 
                    {
                        cout << "Please select a weapon of mass destruction:\n";
                        cout << "1. Nuke\n";
                        cout << "2. Artillery strike\n";
                        cout << "Enter your choice: ";
                        
                        cin >> iWMD; 
                        if(iWMD!=1 && iWMD!=2) 
                        { 
                            cout<<"Please enter a valid option\n!";
                        } 
                        else 
                        { 
                            break;
                        }
                    }while(true);
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
                iCount2++;
            }
            
            country2->Attack(country1);
            cout << endl;
            country1->Attack(country2);
            cout << endl;
            if(iCount1 == 2){
                country1 = country1->getCountry();
                iCount1++;
            }else if(iCount2 == 2){
                country2 = country2->getCountry();
                iCount2++;
            }
            
        }

        std::cout<<"BATTLE SUMMARY: "<<endl;
        std::cout << "Total number of fallen soldiers for " << country1->getName();

        std::cout << ": " << int(f1 / 10 + f1 / 50) - country1->getNumOfSoldiers() << "\n\n";

        std::cout << "Total number of fallen soldiers for " << country2->getName();
        std::cout << ": " << int(f2 / 10 + f2 / 50) - country2->getNumOfSoldiers() << "\n\n";

        country1 = country1->getCountry();
        country2 = country2->getCountry();
        delete country1;
        delete country2;
        if (ally1 != nullptr)
        {
            delete ally1;
        }
        if (ally2 != nullptr)
        {
            delete ally2;
        }

        // Design Mode

        // What are we going to change

        // begin loop
        // pick countries names (2)
        // pick countries funds (2)

        // display units from funds entered

        // want to form alliance when funds reach half, the first time

        // want to add more soldiers?*

        // if other countries about to die, give  a choice to finish them with a WMD

        // end of loop, give user a choice
    }
}
