#include "Phase.h" 

Phase::Phase(std::string p){
    phase = p;
}

/**
 * @brief This function returns the current phase
 * 
 * @return std::string 
 */

std::string Phase::getPhase(){ 
    return phase;
}