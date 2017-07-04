#include <gtest/gtest.h>

template <typename Id>
struct CellId {
    CellId() : id(0) {}
    Id id;
};

namespace {

class TestCellId : public ::testing::Test
{
protected:
    CellId<int> * testCellId;
    virtual void SetUp()
    {
        testCellId = new CellId<int>;
    }
    virtual void TearDown()
    {
        delete testCellId;
    }
};

TEST(Toto,Test)
{
    ASSERT_TRUE(0==-1);
    ASSERT_FALSE(1==1);
}

TEST_F(TestCellId,NegativeCellId)
{
    int & cellId = testCellId->id;
    cellId = -1;
    ASSERT_TRUE(cellId<0);
    EXPECT_EQ(cellId,-1);
}

TEST_F(TestCellId,PositiveCellId)
{
    int & cellId = testCellId->id;
    cellId = 10;
    ASSERT_TRUE(cellId > 0);
    EXPECT_EQ(cellId,10);
}

TEST_F(TestCellId,DISABLED_ZeroCellId)
{
    int & cellId = testCellId->id;
    cellId = 0;
    int* badptr = nullptr;
    *badptr = 2;
    ASSERT_TRUE(cellId == 0);
}

} // namespace

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
