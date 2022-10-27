#include "Artillery.h"

Artillery::Artillery(double funds) : WMD(funds)
{
}

Artillery::~Artillery()
{
}

void Artillery::wmd(){
    ArtilleryStrike();
}

/**
 * @brief Artillery strike for the country
 *
 * Will cost the country a specific amount of funds to be able to execute a strike
 */
void Artillery::ArtilleryStrike()
{
    std::cout << "Artillery strike!\n";
}