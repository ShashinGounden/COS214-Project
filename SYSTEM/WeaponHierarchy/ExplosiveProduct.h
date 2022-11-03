#ifndef EXPLOSIVEPRODUCT_H
#define EXPLOSIVEPRODUCT_H

#include "Weapon.h"

class ExplosiveProduct : public Weapon
{
    public:
    ExplosiveProduct(int P);
    virtual ~ExplosiveProduct();
};
#endif