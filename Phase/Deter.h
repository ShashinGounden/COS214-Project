#ifndef DETER_H
#define DETER_H

#include "Phase.h"

class Deter : public Phase
{
public:
    Deter();
    ~Deter();
    Phase* handleChange(double);
    int attackMethod();    

};

#endif