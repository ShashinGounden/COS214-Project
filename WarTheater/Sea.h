#ifndef SEA_H
#define SEA_H

#include "WarTheater.h"

class Sea : public WarTheater
{
public:
    Sea();
    ~Sea();

private:
    void add(Country *force);
    void remove(Country *force);

    // template method functions
    void warLoop();
    virtual void printBattleSummary();
    virtual void loadBattleArt();
};

#endif