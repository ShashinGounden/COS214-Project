#include "Weapon.h"
#include "RifleProduct.h"

class RifleProduct: public Weapon
{
    RifleProduct:: RifleProduct(int damage): Weapon(damage){}
    RifleProduct:: ~RifleProduct(){}
}