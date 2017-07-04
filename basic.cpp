#include <gtest/gtest.h>

template <typename Id>
struct CellId {
    CellId() : id(0) {}
    Id id;
};

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
    testCellId->id = -1;
    ASSERT_TRUE(testCellId->id<0);
    EXPECT_EQ(testCellId->id,-1);
}

TEST_F(TestCellId,PositiveCellId)
{
    int & cellId = testCellId->id;
    cellId = 10;
    ASSERT_TRUE(cellId > 0);
    EXPECT_EQ(cellId,10);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
