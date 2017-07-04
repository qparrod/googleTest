#include <gtest/gtest.h>

int functionToTest(int a)
{
    if (a<0) {
        std::cerr << "unexpected behavior\n";
        exit(0);
    }
    else if(a==0) return 0;
    else          return 1;
}

TEST(DeathTest,ZeroAndNegativeValues)
{
    ASSERT_EQ(0,functionToTest(0));
    ASSERT_EXIT(functionToTest(-42),::testing::ExitedWithCode(0),"unexpected behavior\n");
}

int main(int argc, char* argv[])
{
    ::testing::GTEST_FLAG(death_test_style)="threadsafe";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
