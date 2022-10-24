#include "Dominate.h" 

Dominate::Dominate() :Phase("Dominate"){}

/**
 * @brief A multipier for attack damage
 * 
 * @return int 
 */

int Dominate::attackMethod(){ 
    return 3;
} 

/**
 * @brief This functions decides which phase to move into depending on the funds available 
 * 
 * @param funds 
 * @return Phase* 
 */

Phase* Dominate::handleChange(double funds){ 
    if(funds<20000.00) 
       return new Deter(); 
    else if(funds<5000.00) 
       return new Seize(); 
    return this;      
}