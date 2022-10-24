#include "Seize.h" 

Seize::Seize() : Phase("seize"){} 

/**
 * @brief A multipier for attack damage
 * 
 * @return int 
 */
int Seize::attackMethod(){ 
    return 1;
} 

/**
 * @brief This functions decides which phase to move into depending on the funds available 
 * 
 * @param funds 
 * @return Phase* 
 */

Phase* Seize::handleChange(double funds){ 
    if(funds>5000) 
        return new Deter(); 
    else if(funds>20000) 
        return new Dominate(); 
    return this;    
}