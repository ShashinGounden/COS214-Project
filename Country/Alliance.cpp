#include "Alliance.h"

Alliance::Alliance() {}

Alliance::~Alliance()
{
    allianceList.clear();
}

void Alliance::addAlliance(Country *c)
{
    allianceList.push_back(c);
}

void Alliance::removeAlliance(Country *c)
{
    allianceList.remove(c);
}