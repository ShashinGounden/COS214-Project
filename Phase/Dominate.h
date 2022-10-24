#ifndef DOMINATE_H
#define DOMINATE_H

#include "Phase.h" 
#include "Dominate.h"
#include "Seize.h"

class Dominate : public Phase
{
public:
    Dominate();
    ~Dominate(){}; 
    Phase* handleChange(double);
    int attackMethod(); 


};

#endif