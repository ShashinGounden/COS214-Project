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


#include <gtest/gtest.h>

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

      if (iChoice == 0)
      {
         cout << "\n\n";
         loadASCIIOptions("/EndGame.txt");
         cout << "\n\n";
::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
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



//Country Test*************************************************************************
TEST(CountryTest, NameGetsAdded) {
    //Create country object ;
    Country country("United States of America", 50000);

    //Test that name gets set correctly when creating country object
    ASSERT_EQ(country.getName(), "United States of America") << "Country not being created properly";
    //Test that funds gets set correctly when creating country object


}
//***************************************************************************************

//Phase Test*************************************************************************
TEST(PhaseTest, PhaseCreatesAndGets) {
    //Create new Phase pointer for Seize phase
    Phase *seize = new Seize();

    //Test that object creates correctly and sets name of phase
    ASSERT_EQ(seize->getPhase(), "Seize") << "The creation of the object is not correct";


    //Test that attackMethod() returns the correct value
    EXPECT_EQ(seize->attackMethod(), 1);

    //Test change of Phase
    Phase * changeInPhase = seize->handleChange(5001);
    EXPECT_EQ(changeInPhase->getPhase(), "Deter") << "The Phases are not being changed\n";

    //Delete Pointers
    delete seize;
    delete changeInPhase;
    changeInPhase = nullptr;
    seize = nullptr;


}
//***************************************************************************************

//Transport Test*************************************************************************
TEST(TransportTest,TestTransport)
{
    //Create Transport object and set its values
    Transport transport ;
    transport.setHealth(50) ;
    transport.setDefence("New Defense") ;

    //Test if the values have been set correctly
    ASSERT_EQ(transport.getDefence(),"New Defense") << "Defense has not been correctly set\n" ;
    ASSERT_EQ(transport.getHealth(),50) << "Health has not been correctly set\n" ;

    //Change the values for a second test
    transport.setHealth(100) ;
    transport.setDefence("New Defense 2") ;

    //Test if the values have been set correctly
    ASSERT_EQ(transport.getDefence(),"New Defense 2") << "Defense 2 has not been correctly set\n" ;
    ASSERT_EQ(transport.getHealth(),100) << "Health 2 has not been correctly set\n" ;
}
//***************************************************************************************

