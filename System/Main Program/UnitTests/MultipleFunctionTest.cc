#include <gtest/gtest.h>
#include "../ArmyHierarchy/Army.h"
#include "../Phase/Phase.h"
#include "../Phase/Seize.h"

//MultipleFunctions Test*************************************************************************
TEST(MultipleFunctionsTest, CheckAFewFunctions) {
    //Create Army object
    Army *army = new Army("Republic of South Africa", 100, 100, 0);

    //Check that name has been initialised
    EXPECT_EQ(army->getName(), "Republic of South Africa") << "getName() does not return the correct name";

    //Check that the number of people in army are set correctly
    ASSERT_EQ(army->getNumOfSoldiers(), 100) << "Number of soldiers are incorrect";

    army->populateUnit(100, 100, 100);

    //Check that the number of people in army are set correctly
    ASSERT_EQ(army->getNumOfSoldiers(), 300)
                                << "Values were not correctly populated after populateUnit(int,int,int) called";


    //Create GroundUNit object for testing
    GroundUnit *groundUnit = new GroundUnit("Test Unit");

    //Populate ground unit with 10
    groundUnit->populateUnit(10);

    //Test that the value was correctly set
    EXPECT_EQ(groundUnit->getSize(), 10) << "Size of GroundUnit not correctly set";

    //Test the power of the ground unit
    ASSERT_EQ(groundUnit->getPower(), 1000) << "getPower() does not return the correct value";

    //Create Medic Factory
    MedicFactory *medicFactory = new MedicFactory();

    //Create a new medic
    Person *personOne = medicFactory->createPerson(1234, 50, "revive");

    //Test that the newly created medic has been done correctly
    ASSERT_EQ(personOne->getHealth(), 100) << "Health has not been correctly set";
    ASSERT_EQ(personOne->getSkill(), "revive") << "Skills has not been correctly set";
    ASSERT_EQ(personOne->getID(), 1234) << "ID has not been correctly set";

    //Ensure that clone() function works accordingly
    Person *personTwo = personOne->clone();
    ASSERT_EQ(personTwo->getHealth(), 100) << "Health has not been correctly set after clone()";
    ASSERT_EQ(personTwo->getSkill(), "revive") << "Skills has not been correctly set after clone()";
    ASSERT_EQ(personTwo->getID(), 1234) << "ID has not been correctly set after clone()";


    //Create Medic object
    Medic *medic = new Medic(5689, 50, "revive");

    //Test if all values have been coorectly set
    //getID()
    EXPECT_EQ(medic->getID(), 5689) << "ID value has not been correctly set";
    //getHealth()
    EXPECT_EQ(medic->getHealth(), 100) << "Health value has not been correctly set";
    //getSkill()
    EXPECT_EQ(medic->getSkill(), "revive") << "Revive value has not been correctly set";

    //Test that clone function operates correctly by testing each function after the assignment
    Person *newMedic = medic->clone();
    ASSERT_EQ(newMedic->getHealth(), 100) << "Health value after clone() has not been correctly set";
    ASSERT_EQ(newMedic->getID(), 5689) << "ID value after clone() has not been correctly set";
    ASSERT_EQ(newMedic->getSkill(), "revive") << "Health value after clone() has not been correctly set";

    //Create new Phase pointer for Seize phase
    Phase *seize = new Seize();

//Test that object creates correctly and sets name of phase
    ASSERT_EQ(seize->getPhase(), "Seize") << "The creation of the object is not correct";


//Test that attackMethod() returns the correct value
    EXPECT_EQ(seize->attackMethod(), 1);

//Test change of Phase
    Phase *changeInPhase = seize->handleChange(5001);
    EXPECT_EQ(changeInPhase->getPhase(), "Deter") << "The Phases are not being changed\n";

//Delete Pointers
    delete seize;
    delete changeInPhase;
    //Delete the memory allocated

    delete newMedic;
    delete medic;
    delete groundUnit;
    delete army;
    delete personOne;
    delete personTwo;
}