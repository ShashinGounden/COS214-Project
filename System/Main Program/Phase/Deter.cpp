#include "Deter.h" 

Deter::Deter() :Phase("Deter"){
    std::cout<< "will continue to press the attack\n\n";
} 

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
    std::cout<<"makes no changes to war plans\n\n";   
    return this;   
}




