#include <gtest/gtest.h>

TEST(Toto,Test)
{
    EXPECT_EQ(0,1)     << "diagnostic message 1";
    ASSERT_TRUE(2==2)  << "diagnostic message 2";
    ASSERT_FALSE(3==3) << "diagnostic message 3";
    ASSERT_TRUE(4==5)  << "diagnostic message 4";
}
int main(int argc, char* argv[])
{
    ::testing::GTEST_FLAG(print_time) = false;
    ::testing::GTEST_FLAG(color) = "no";
    ::testing::GTEST_FLAG(repeat) = 3;
    ::testing::GTEST_FLAG(output) = "xml";
    //::testing::GTEST_FLAG(catch_exceptions)=0;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
