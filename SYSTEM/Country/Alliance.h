#ifndef ALLIANCE_H
#define ALLIANCE_H

#include "Country.h"

class Alliance
{
public:
    Alliance();
    ~Alliance();

    void addAlliance(Country *);
    void removeAlliance(Country *);
    void update();

private:
    std::list<Country *> allianceList;
    std::list<std::string> responses;
};

#endif