#ifndef BAZOOKA_H
#define BAZOOKA_H

#include "ExplosiveProduct.h"

class Bazooka : public ExplosiveProduct
{
    public:
    Bazooka(int damage);
    ~Bazooka();
};

#endif
