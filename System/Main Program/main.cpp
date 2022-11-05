/**
 * @file main.cpp
 * @author @JordanTimberlake @ShashinGounden @Tymac15 @u20612894 @u21598267
 * @brief MAIN DOCUMENT TO RUN with makefile
 *
 * @version 3.1
 * @date 2022-10-31
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
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

// Includes here
#include "Country/Country.h"
#include "ArmyHierarchy/Army.h"
#include "Country/WMD.h"
#include "Country/Nuke.h"
#include "Country/Artillery.h"
#include "WarTheater/Airspace.h"
#include "WarTheater/Sea.h"


void loadASCIIOptions(string fileName);

int main()
{

   // loading Welcome Screen Text
   loadASCIIOptions("/Welcome.txt");

   // Press enter to continue
   loadASCIIOptions("/BeginGame.txt");

   // Waits for enter key to be pressed
   cin.get();

   // load SelectBattle
   loadASCIIOptions("/SelectBattle.txt");

   // Select battle
   int iChoice = 3;
   cout << "Enter your choice [1/2] (Enter 0 to exit): ";
   cin >> iChoice;

   while (true)
   {
      cout << endl;
      if (iChoice == 1)
      {
         Sea DunkirkTheater;
         DunkirkTheater.startGenericBattle();
         cout << "Enter 0 to exit the program and 3 to run the simulation again: ";
         cin >> iChoice;
      }
      else if (iChoice == 2)
      {
         Airspace PearlHarborTheater;
         PearlHarborTheater.startGenericBattle();
         cout << "Enter 0 to exit the program 3 to run the simulation again: ";
         cin >> iChoice;
      }
      else if (iChoice == 0)
      {
         cout << "\n\n";
         loadASCIIOptions("/EndGame.txt");
         cout << "\n\n";
         return 0;
      }
      else if (iChoice == 3)
      {
         loadASCIIOptions("/SelectBattle.txt");
         cout << "Enter your choice [1/2]: ";
         cin >> iChoice;
      }
      else
      {
         cout << "Please enter a valid choice [1/2]: ";
         cin >> iChoice;
      }
   }

    return 0 ;
}

/**
 * @brief Loads the relevant ASCII art when starting the simulation
 *
 * @param fileName The name of the textfile to output
 */

void loadASCIIOptions(string fileName)
{

   char buff[FILENAME_MAX]; // create string buffer to hold path
   GetCurrentDir(buff, FILENAME_MAX);
   string current_working_dir(buff);
   string filepath = current_working_dir + fileName;
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
      cout << "Failed to load Welcome.txt" << endl;
   }

   inFile.close();
}