#include <iostream>

// Includes here
#include "Country/Country.h"
#include "ArmyHierarchy/Army.h"

int main()
{
    Country *United_States = new Country(2000);
    United_States->setName("United States Of America");
    Country *Germany = new Country(2000);
    Germany->setName("NAZI Scum");
    United_States->Attack();
    Germany->Retreat();

    delete United_States;
    delete Germany;
    return 0;
}
