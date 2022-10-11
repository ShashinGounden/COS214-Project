#include <iostream>

// Includes here
#include "Country/Country.h"

int main()
{
    Country* United_States = new Country("United States of America");
    Country* Germany = new Country("Germany");
    United_States->Attack(Germany);
    return 0;
}
