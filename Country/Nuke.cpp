#include "Nuke.h"

Nuke::Nuke(Country *c) : WMD(c)
{
}

Nuke::~Nuke()
{
}

void Nuke::wmd()
{
    deployNuke();
}

void Nuke::Attack(Country* c)
{
    if (owner != NULL)
    {
       if(owner->getFunds()>20000) 
        {
           std::cout << owner->getName() << " ";
           wmd();  
           c->takeDamage(1500000); 
           owner->addFunds(-25000); 
        } 
        owner->Attack(c);
    }
}

void Nuke::takeDamage(int d)
{
    if (owner != NULL)
        owner->takeDamage(d);
}

/**
 * @brief country deploys nuke on opposing country
 *
 * Costs the country a certain amount of funds to be able to have a
 * nuke in its arsenal - Will cost more than a artillery strike
 */
void Nuke::deployNuke()
{
    std::cout<< owner->getName() << "deploys nuke!\n";
}