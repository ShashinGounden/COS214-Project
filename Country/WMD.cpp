#include "WMD.h"


WMD::WMD(Country *c) 
{
    owner = c;
}

WMD::~WMD()
{ 
    if(owner!=NULL) 
       delete owner; 

}

void WMD::wmd() {}
