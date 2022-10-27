#include "Nuke.h"

Nuke::Nuke(double funds) : WMD(funds)
{
}

Nuke::~Nuke()
{
}

void Nuke::wmd(){
    deployNuke();
}

/**
 * @brief country deploys nuke on opposing country
 *
 * Costs the country a certain amount of funds to be able to have a
 * nuke in its arsenal - Will cost more than a artillery strike
 */
void Nuke::deployNuke()
{
    std::cout << "Deploy Nuke!\n";
}