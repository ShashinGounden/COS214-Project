#include <iostream>

// Includes here
#include "Country/Country.h"
#include "ArmyHierarchy/Army.h"

int main()
{
    Country* United_States = new Army();
    United_States->setName("United States Of America");
    Country* Germany = new Army();
    Germany->setName("NAZI Scum");
    United_States->Attack(Germany);
    return 0;
}
