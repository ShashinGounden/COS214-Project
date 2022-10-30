#include "Artillery.h"

Artillery::Artillery(Country *c) : WMD(c)
{
}

Artillery::~Artillery()
{
}

void Artillery::wmd()
{
    ArtilleryStrike();
}

/**
 * @brief
 *
 */
void Artillery::Attack(Country* c)
{
    if (owner != NULL)
    {
        std::cout << owner->getName() << " ";
        ArtilleryStrike();
        owner->Attack(c);
    }
}

void Artillery::takeDamage(int g)
{
    if(owner!=NULL)
       owner->takeDamage(g);
}
/**
 * @brief Artillery strike for the country
 *
 * Will cost the country a specific amount of funds to be able to execute a strike
 */
void Artillery::ArtilleryStrike()
{
    std::cout << "Artillery strike!\n";

    // Add text art here - @ShashinGounden
}