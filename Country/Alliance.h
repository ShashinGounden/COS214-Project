#ifndef ALLIANCE_H
#define ALLIANCE_H

#include "Country.h"

class Alliance : public Country
{
public:
    Alliance();
    ~Alliance();

    void addAlliance(Country *);
    void removeAlliance(Country *);

private:
    std::list<Country *> allianceList;
};

#endif