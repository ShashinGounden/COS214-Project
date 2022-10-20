#include "RifleFactory.h"
#include "../Weapon.h"

class RifleFactory : public WeaponFactory
{
    RifleFactory:: RifleFactory(){}

    Weapon* RifleFactory:: CreateLongRange()
    {
        Weapon* w = new M1917Enfield(60);
        return w;
    }

    Weapon* RifleFactory:: CreateShortRange()
    {
        Weapon* w = new M1Garand(60);
        return w;
    }
    
    RifleFactory:: ~RifleFactory(){}
}