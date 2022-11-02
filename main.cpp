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
   string filepath = current_working_dir + "/Welcome.txt";
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


   //Press enter to continue
   GetCurrentDir(buff, FILENAME_MAX);
   string current_working_dir1(buff);
    filepath = current_working_dir1 + "/BeginGame.txt";
    line = "";
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
      cout << "Failed to load BeginGame.txt" << endl;
   }

   inFile.close();

   //Waits for enter key to be pressed
   cin.get();

   //Select battle
   GetCurrentDir(buff, FILENAME_MAX);
   string current_working_dir2(buff);
    filepath = current_working_dir2 + "/SelectBattle.txt";
    line = "";
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
      cout << "Failed to load SelectBattle.txt" << endl;
   }
   inFile.close();

   int iChoice = -1;
   cout<<"Enter your choice [1/2]: ";
   cin>>iChoice;
   cout<<endl;

   if (iChoice == 1)
   {
      Sea DunkirkTheater;
      DunkirkTheater.startGenericBattle();

   }
   else if (iChoice == 2)
   {
      Airspace PearlHarborTheater;
      PearlHarborTheater.startGenericBattle();
   }

   
   // Testing decorator
   /*
    */


   return 0;
}
