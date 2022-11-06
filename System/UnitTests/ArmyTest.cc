#include <gtest/gtest.h>
#include "../ArmyHierarchy/Army.h"

//@JordanTimberlake
//Army Test*************************************************************************
TEST(ArmyTest, CheckArmyFunctions) {
    //Create Army object
    Army * army = new Army("Republic of South Africa",100,100,0) ;

    //Check that name has been initialised
    EXPECT_EQ(army->getName(),"Republic of South Africa")  << "getName() does not return the correct name";

    //Check that the number of people in army are set correctly
    ASSERT_EQ(army->getNumOfSoldiers(),100) << "Number of soldiers are incorrect";

    army->populateUnit(100,100,100) ;

    //Check that the number of people in army are set correctly
    ASSERT_EQ(army->getNumOfSoldiers(),300) << "Values were not correctly populated after populateUnit(int,int,int) called" ;

    delete army ;

}
