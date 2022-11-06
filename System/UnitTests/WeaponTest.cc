#include <gtest/gtest.h>
#include "../WeaponHierarchy/Weapon.h"
//@ShashinGounden
// Weapon Test************************************************
TEST(WeaponTest,TestWeaponsCreated)
{

    //Create Weapon object
    Weapon * weapon = new Weapon(57) ;
    EXPECT_EQ(weapon->fire(),57) ;

    delete weapon ;

}
//@JordanTimberlake
TEST(WeaponTest2,TestWeaponsCreated)
{

    //Create Weapon object
    Weapon * weapon = new Weapon(1000) ;
    EXPECT_EQ(weapon->fire(),1000) ;

    delete weapon ;

}
//@JonelAlbuquerque
TEST(WeaponTest3,TestWeaponsCreated)
{

    //Create Weapon object
    Weapon * weapon = new Weapon(547) ;
    EXPECT_EQ(weapon->fire(),547) ;

    delete weapon ;

}

//************************************************************