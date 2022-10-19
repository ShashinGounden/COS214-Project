#include "ExplosiveProduct.h"
#include "GasBomb.h"

class GasBomb : public ExplosiveProduct
{
    GasBomb:: GasBomb(int damage):ExplosiveProduct(damage){}
    
    GasBomb:: ~GasBomb(){}
}