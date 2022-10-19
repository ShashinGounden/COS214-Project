#include "Weapon.h"
#include "PistolProduct.h"

class PistolProduct: public Weapon
{
    PistolProduct:: PistolProduct(int damage): Weapon(damage){}
    PistolProduct:: ~PistolProduct(){}
}