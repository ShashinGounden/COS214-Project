#include "WMD.h"

WMD::WMD(Country *c)
{
    owner = c;
}

WMD::~WMD()
{
    
}

void WMD::Retreat()
{
    if (owner != NULL)
        owner->Retreat();
}

double WMD::getFunds()
{
    if (owner != NULL)
       return owner->getFunds();
    return 0.00;
}

std::string WMD::getName()
{
    if (owner != NULL)
       return owner->getName();
    return "";
}

bool WMD::surrender(Country *c)
{
    if (owner != NULL)
       return owner->surrender(c); 
    return false;   
}

void WMD::joinAlliance(Alliance * all) 
{ 
   if(owner!=NULL) 
       owner->joinAlliance(all);

}  

void WMD::addFunds(double f)
{ 

    if(owner!=NULL) 
      owner->addFunds(f);
}

void WMD::notify() 
{
    if(owner!=NULL) 
       owner->notify();
}

void WMD::wmd()
{
}

Country* WMD::getCountry(){ 
    if(owner!=NULL)
       return owner->getCountry(); 
    return NULL;   
}