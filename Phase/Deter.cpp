#include "Deter.h" 

Deter::Deter() :Phase("Deter"){} 

/**
 * @brief A multipier for attack damage
 * 
 * @return int 
 */

int Deter::attackMethod(){ 
    return 2;
}

/**
 * @brief This functions decides which phase to move into depending on the funds available 
 * 
 * @param funds 
 * @return Phase* 
 */

Phase* Deter::handleChange(double funds){ 
    if(funds>20000.00) 
       return new Dominate(); 
    else if(funds<5000.00) 
       return new Seize(); 
    return this;   
}




