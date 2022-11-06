#include <gtest/gtest.h>
#include "../Country/Country.h"



//Country Test*************************************************************************
TEST(CountryTest, NameGetsAdded) {
    //Create country object ;
    Country country("United States of America", 50000);
    //Test that name gets set correctly when creating country object
    ASSERT_EQ(country.getName(), "United States of America") << "Country not being created properly";
    //Test that funds gets set correctly when creating country object
}
//***************************************************************************************

TEST(CountryTest2, NameGetsAdded) {
    //Create country object ;
    Country country("Germany", 50000);
    //Test that name gets set correctly when creating country object
    ASSERT_EQ(country.getName(), "Germany") << "Country not being created properly";
    //Test that funds gets set correctly when creating country object
    EXPECT_NE(country.getFunds(),50000) ;
}
//***************************************************************************************
