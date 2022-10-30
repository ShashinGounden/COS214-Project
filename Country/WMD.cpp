#include "WMD.h"

WMD::WMD() : Country("test", 20.0)
{
    owner = NULL;
}

WMD::WMD(Country *c) : Country(c->getName(), c->getFunds())
{
    owner = c;
}

WMD::~WMD()
{}

void WMD::wmd() {}
