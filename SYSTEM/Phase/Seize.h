#ifndef SEIZE_H
#define SEIZE_H

#include "Phase.h" 
#include "Deter.h" 
#include "Dominate.h"

class Seize : public Phase
{
public:
    Seize();
    ~Seize(){}; 
    Phase* handleChange(double); 
    int attackMethod(); 


};

#endif