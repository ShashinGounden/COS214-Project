#include <iostream>

// Includes here
#include "Country/Country.h"
#include "ArmyHierarchy/Army.h"

int main()
{
    Country* United_States = new Country();
    United_States->setName("United States Of America");
    Country* Germany = new Country();
    Germany->setName("NAZI Scum");
    United_States->Attack();

    delete United_States;
    delete Germany;
    return 0;
}
