#ifndef SEA_H
#define SEA_H

#include "WarTheater.h"

class Sea : public WarTheater
{
public:
    Sea();
    ~Sea();

private:
     void add(Country* force)=0;
     void remove(Country* force) = 0;

     //template method functions
     void warLoop() = 0;
     virtual void printBattleSummary();
     virtual void loadBattleArt();
};

#endif