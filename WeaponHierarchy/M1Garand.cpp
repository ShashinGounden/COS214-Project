#include "RifleProduct.h"
#include "M1Garand.h"

class M1Garand : public RifleProduct
{
    M1Garand:: M1Garand(int damage):RifleProduct(damage){}
    
    M1Garand:: ~M1Garand(){}
}