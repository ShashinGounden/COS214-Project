#include "Seize.h" 

Seize::Seize() : Phase("Seize"){ 
    std::cout<< "plans to take the initiative\n";
} 

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
    std::cout<<"makes no changes to war plans\n";    
    return this;    
}