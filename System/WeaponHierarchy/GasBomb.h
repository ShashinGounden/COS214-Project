#ifndef GASBOMB_H
#define GASBOMB_H

#include "ExplosiveProduct.h"

class GasBomb : public ExplosiveProduct
{
    public:
    GasBomb(int damage);
    ~GasBomb();
};
#endif