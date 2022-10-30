#ifndef PHASE_H
#define PHASE_H
#include <string>
#include <iostream>

class Phase
{
public:
    Phase(std::string);
    virtual ~Phase(){};
    virtual Phase *handleChange(double) = 0;
    virtual int attackMethod() = 0;
    std::string getPhase();

protected:
    std::string phase;
};

#endif