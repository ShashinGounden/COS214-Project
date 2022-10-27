#ifndef WMD_H
#define WMD_H

#include "Country.h"
class Country;

class WMD : public Country
{
public:
    WMD(double);
    ~WMD();

    virtual void wmd() = 0;

protected:
    Country* owner;
};

#endif