#include "Weapon.h"
#include "ExplosiveProduct.h"

class ExplosiveProduct: public Weapon
{
    ExplosiveProduct:: ExplosiveProduct(int damage): Weapon(damage){}
    ExplosiveProduct:: ~ExplosiveProduct(){}
}