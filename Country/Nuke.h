#ifndef NUKE_H
#define NUKE_H

#include "WMD.h"

class Nuke : public WMD
{
public:
    Nuke(double);
    ~Nuke();

    void wmd();
    void deployNuke();
};

#endif