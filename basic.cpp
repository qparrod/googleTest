#include <gtest/gtest.h>

template <typename Id>
struct CellId
{
public:
    CellId() : id(0) {}

    Id get() { return id; }
    void set(Id newId) { id = newId; }

private:
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
    ASSERT_FALSE(1=="toto");
}

TEST_F(TestCellId,NegativeCellId)
{
    testCellId->set(-1);
    ASSERT_TRUE(testCellId->get()<0);
    EXPECT_EQ(testCellId->get(),-1);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
