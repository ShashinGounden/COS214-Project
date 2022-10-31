#include "Artillery.h"

Artillery::Artillery(Country *c) : WMD(c)
{
    std::cout<<owner->getName()<<" has prepared heavy artillery!\n";
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
        if(owner->getFunds()>20000) 
        {
           std::cout << owner->getName() << " ";
           wmd();  
           c->takeDamage(1300000); 
           owner->addFunds(-24000); 
        }
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
    std::cout <<owner->getName() << "has launched artillery strike!\n";

    // Add text art here - @ShashinGounden
}