#include <gtest/gtest.h>
#include "../ArmyHierarchy/Transport/Transport.h"
//Transport Test*************************************************************************
TEST(TransportTest,TestTransport)
{
//Create Transport object and set its values
Transport transport ;
transport.setHealth(50) ;
transport.setDefence("New Defense") ;

//Test if the values have been set correctly
ASSERT_EQ(transport.getDefence(),"New Defense") << "Defense has not been correctly set\n" ;
ASSERT_EQ(transport.getHealth(),50) << "Health has not been correctly set\n" ;

//Change the values for a second test
transport.setHealth(100) ;
transport.setDefence("New Defense 2") ;

//Test if the values have been set correctly
ASSERT_EQ(transport.getDefence(),"New Defense 2") << "Defense 2 has not been correctly set\n" ;
ASSERT_EQ(transport.getHealth(),100) << "Health 2 has not been correctly set\n" ;
}
//***************************************************************************************
