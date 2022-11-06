#include <gtest/gtest.h>
#include "../PersonHierarchy/Medic.h"
//@ShashinGounden
//Medic Test*************************************************************************
TEST(MedicTest, CheckMedicFunctions) {

    //Create Medic object
    Medic * medic = new Medic(5689,50,"revive") ;

    //Test if all values have been coorectly set
    //getID()
    EXPECT_EQ(medic->getID(),5689) << "ID value has not been correctly set";
    //getHealth()
    EXPECT_EQ(medic->getHealth(),100) << "Health value has not been correctly set";
    //getSkill()
    EXPECT_EQ(medic->getSkill(),"revive") << "Revive value has not been correctly set";

    //Test that clone function operates correctly by testing each function after the assignment
    Person * newMedic = medic->clone() ;
    ASSERT_EQ(newMedic->getHealth(),100) << "Health value after clone() has not been correctly set";
    ASSERT_EQ(newMedic->getID(),5689) << "ID value after clone() has not been correctly set";
    ASSERT_EQ(newMedic->getSkill(),"revive") << "Health value after clone() has not been correctly set";

    delete newMedic ;
    delete medic ;

}
//***********************************************************************************