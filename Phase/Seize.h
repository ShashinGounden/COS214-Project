#ifndef SEIZE_H
#define SEIZE_H

#include "Phase.h"

class Seize : public Phase
{
public:
    Seize();
    ~Seize(); 
    Phase* handleChange(double); 
    int attackMethod(); 


};

#endif