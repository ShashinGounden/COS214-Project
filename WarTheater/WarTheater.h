#ifndef WARTHEATER_H
#define WARTHEATER_H
#include "../Country/Country.h"
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class WarTheater
{
public:
    WarTheater();
    // making the base class destructor virtual to avoid segmentation faults when deleting children class objects
    virtual ~WarTheater();

    // Pure virtual functions to be implemented in the children classes (Airspace and Sea)
    virtual void add(Country *force) = 0;
    virtual void remove(Country *force) = 0;
    virtual void warLoop() = 0;

    // Template Method functions
    virtual void printBattleSummary() = 0;
    virtual void loadBattleArt() = 0;
    void startGenericBattle()
    {
        printBattleSummary();
        loadBattleArt();
        warLoop();
    }

protected:
    // list of countries in the war theatre stored in vector
    vector<Country *> countries;
};

#endif