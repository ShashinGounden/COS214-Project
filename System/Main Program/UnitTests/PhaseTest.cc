#include <gtest/gtest.h>
#include "../Phase/Phase.h"
#include "../Phase/Seize.h"
//Phase Test*************************************************************************
TEST(PhaseTest, PhaseCreatesAndGets) {
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
    changeInPhase = nullptr;
    seize = nullptr;


}
//***************************************************************************************
