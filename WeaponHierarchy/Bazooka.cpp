#include "ExplosiveProduct.h"
#include "Bazooka.h"

class Bazooka : public ExplosiveProduct
{
    Bazooka:: Bazooka(int damage):ExplosiveProduct(damage){}
    
    Bazooka:: ~Bazooka(){}
}