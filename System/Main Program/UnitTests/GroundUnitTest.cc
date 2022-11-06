#include <gtest/gtest.h>
#include "../ArmyHierarchy/GroundUnit.h"


//GroundUnitTest *************************************************
TEST(GUTest,CheckClassFunctions)
{

    //Create GroundUNit object for testing
    GroundUnit * groundUnit = new GroundUnit("Test Unit") ;

    //Populate ground unit with 10
    groundUnit->populateUnit(10) ;

    //Test that the value was correctly set
    EXPECT_EQ(groundUnit->getSize(),10) << "Size of GroundUnit not correctly set";

    //Test the power of the ground unit
    ASSERT_EQ(groundUnit->getPower(),600)  << "getPower() does not return the correct value";

    //Delete the memory allocated
    delete groundUnit;



}
//**********************************************************************