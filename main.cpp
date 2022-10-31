#include <iostream>
#include <string>

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
    //Sea newSpace;
    //newSpace.startGenericBattle();

    //Testing decorator 
    Country* Sweden=new Country("Sweden",200000); 
    Country* Ireland=new Country("Ireland",200000); 
    
    std::cout<<"\n"; 

    Sweden->Attack(Ireland); 
    Ireland->Attack(Sweden); 

    char ans='n'; 
    std::cout<<"Would you like to add a nuke to Sweden? [Y/N]:"; 
    cin>>ans; 

    if(ans=='Y' || ans=='y') 
       Sweden=new Nuke(Sweden); 

    std::cout<<"Would you like to add artillery to Irelnand? [Y/N]: "; 
    cin>>ans; 

    if(ans=='Y' || ans=='y') 
       Ireland=new Artillery(Ireland); 

    Sweden->Attack(Ireland); 
    Ireland->Attack(Sweden);

    return 0;
}
