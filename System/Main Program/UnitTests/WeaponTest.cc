#include <gtest/gtest.h>
#include "../WeaponHierarchy/Weapon.h"

//Weapon Test************************************************
TEST(WeaponTest,TestWeaponsCreated)
{

    //Create Weapon object
    Weapon * weapon = new Weapon(57) ;
    EXPECT_EQ(weapon->fire(),57) ;

    delete weapon ;

}

TEST(WeaponTest2,TestWeaponsCreated)
{

    //Create Weapon object
    Weapon * weapon = new Weapon(1000) ;
    EXPECT_EQ(weapon->fire(),1000) ;

    delete weapon ;

}

TEST(WeaponTest3,TestWeaponsCreated)
{

    //Create Weapon object
    Weapon * weapon = new Weapon(547) ;
    EXPECT_EQ(weapon->fire(),547) ;

    delete weapon ;

}

//************************************************************