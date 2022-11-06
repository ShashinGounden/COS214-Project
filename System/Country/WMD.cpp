#include "WMD.h" 

/**
 * @brief Construct a new WMD::WMD object
 * 
 * @param c 
 */
WMD::WMD(Country *c)
{
    owner = c;
}

/**
 * @brief Destroy the WMD::WMD object
 * 
 */
WMD::~WMD()
{
    
}

/**
 * @brief Country's troops retreat
 * 
 */
void WMD::Retreat()
{
    if (owner != NULL)
        owner->Retreat();
}

/**
 * @brief get Country's funds
 * 
 * @return double 
 */

double WMD::getFunds()
{
    if (owner != NULL)
       return owner->getFunds();
    return 0.00;
}

/**
 * @brief return the name of Country holding this weapon
 * 
 * @return std::string 
 */
std::string WMD::getName()
{
    if (owner != NULL)
       return owner->getName();
    return "";
}

/**
 * @brief checks if Country holding this weapon surrenders
 * 
 * @param c opposing Country
 * @return true 
 * @return false 
 */
bool WMD::surrender(Country *c)
{
    if (owner != NULL)
       return owner->surrender(c); 
    return false;   
}

/**
 * @brief Joins an alliance for support
 * 
 * @param all alliance to join
 */
void WMD::joinAlliance(Alliance * all) 
{ 
   if(owner!=NULL) 
       owner->joinAlliance(all);

}  

/**
 * @brief Adds funds to the holder of this weapon
 * 
 * @param f funds to be added
 */
void WMD::addFunds(double f)
{ 

    if(owner!=NULL) 
      owner->addFunds(f);
}

/**
 * @brief Contacts allies
 * 
 */
void WMD::notify() 
{
    if(owner!=NULL) 
       owner->notify();
}
/**
 * @brief will call appropraite wmd
 * 
 */
void WMD::wmd()
{
}

/**
 * @brief returns the owner of this weapon
 * 
 * @return Country* 
 */
Country* WMD::getCountry(){ 
    if(owner!=NULL)
       return owner->getCountry(); 
    return NULL;   
} 

/**
 * @brief returns the number of soldiers of Country holding this weapon
 * 
 * @return int 
 */
int WMD::getNumOfSoldiers(){
    if(owner!=NULL) 
       return owner->getNumOfSoldiers(); 
    return 0;   
}