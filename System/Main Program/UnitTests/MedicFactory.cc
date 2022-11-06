#include <gtest/gtest.h>
#include "../PersonHierarchy/PersonFactory/MedicFactory.h"
//MedicFactory Test*************************************************************************
TEST(MedicFactoryTest, CheckMedicFactoryFunctions) {

    //Create Medic Factory
    MedicFactory * medicFactory = new MedicFactory();

    //Create a new medic
    Person * personOne = medicFactory->createPerson(1234,50,"revive") ;

    //Test that the newly created medic has been done correctly
    ASSERT_EQ(personOne->getHealth(),100) << "Health has not been correctly set" ;
    ASSERT_EQ(personOne->getSkill(),"revive") << "Skills has not been correctly set" ;
    ASSERT_EQ(personOne->getID(),1234) << "ID has not been correctly set" ;

    //Ensure that clone() function works accordingly
    Person * personTwo = personOne->clone() ;
    ASSERT_EQ(personTwo->getHealth(),100) << "Health has not been correctly set after clone()" ;
    ASSERT_EQ(personTwo->getSkill(),"revive") << "Skills has not been correctly set after clone()" ;
    ASSERT_EQ(personTwo->getID(),1234) << "ID has not been correctly set after clone()" ;

}