
#ifndef AIRSPACE_H
#define AIRSPACE_H
#include "WarTheater.h"

class Airspace : public WarTheater
{
public:
    Airspace();
    ~Airspace();

private:
     void add(Country* force)=0;
     void remove(Country* force) = 0;

    //template Method functions
     void warLoop() = 0;
     virtual void printBattleSummary();
     virtual void loadBattleArt();
};
#endif
