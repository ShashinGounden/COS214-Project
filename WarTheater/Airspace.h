
#ifndef AIRSPACE_H
#define AIRSPACE_H
#include "WarTheater.h"

class Airspace : public WarTheater
{
public:
    Airspace();
    ~Airspace();

private:
    void add(Country *force);
    void remove(Country *force);

    // template Method functions
    void warLoop();
    void printBattleSummary();
    void loadBattleArt();
};
#endif
