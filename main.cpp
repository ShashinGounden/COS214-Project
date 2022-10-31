/**
 * @file main.cpp
 * @author @JordanTimberlake @ShashinGounden @Tymac15 @u20612894 @u21598267
 * @brief MAIN DOCUMENT TO RUN with makefile 
 * 
 * make
 * make run
 * make clean
 * 
 * @version 0.1
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

int main()
{
   // loading Welcome Screen Text
   char buff[FILENAME_MAX]; // create string buffer to hold path
   GetCurrentDir(buff, FILENAME_MAX);
   string current_working_dir(buff);
   string filepath = current_working_dir + "/Nuke.txt";
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

   // Sea newSpace;
   // newSpace.startGenericBattle();

   // Testing decorator
   /*
    */
   Country *Sweden = new Country("Sweden", 200000);
   Country *Ireland = new Country("Ireland", 200000);

   std::cout << "\n";

   Sweden->Attack(Ireland);
   Ireland->Attack(Sweden);

   char ans = 'n';
   std::cout << "Would you like to add a nuke to Sweden? [Y/N]:";
   cin >> ans;

   if (ans == 'Y' || ans == 'y')
   {
      // Sweden = new Nuke(Sweden);

      std::cout << "Would you like to add artillery to Ireland? [Y/N]: ";
      cin >> ans;
   }

   if (ans == 'Y' || ans == 'y'){
      Ireland = new Artillery(Ireland);
   }

   Sweden->Attack(Ireland);
   Ireland->Attack(Sweden);

   delete Sweden;
   delete Ireland;

   return 0;
}
