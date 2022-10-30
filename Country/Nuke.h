#ifndef NUKE_H
#define NUKE_H

#include "WMD.h"

class Nuke : public WMD
{
public:
    Nuke(Country*);
    ~Nuke();

    void wmd();
    void deployNuke(); 

    void Attack(Country*); 
    void takeDamage(int);
};

#endif