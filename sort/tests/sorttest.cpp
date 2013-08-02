#include <limits.h>
#include "../Bubble.h"
#include "testsim.h"
#include "gtest/gtest.h"

using namespace ts;


TEST(MetaTest, CreateVect)
{
    // Test vector size
    vect v1 = CreateVect(307);
    decltype(v1.size()) sz = 307;
    ASSERT_EQ(sz, v1.size());

    // Test lower and upper bounds
    vect v2 = CreateVect(1000, 5, 200);
    for (auto i : v2)
    {
        ASSERT_LE(5, i);
        ASSERT_GT(200, i);
    }
}


TEST(MetaTest, IsSorted)
{
    vect v1 = {1, 2, 3, 5, 30, 2000};
    vect v2 = {};
    vect v3 = {-6};
    vect v4 = {4, 5, 7, 6};
    vect v5 = {1, 1, 1, 2, 3};
    vect v6 = {1, 2, 3, 3, -4};
    ASSERT_TRUE(IsSorted(v1));
    ASSERT_TRUE(IsSorted(v2));
    ASSERT_TRUE(IsSorted(v3));
    ASSERT_FALSE(IsSorted(v4));
    ASSERT_TRUE(IsSorted(v5));
    ASSERT_FALSE(IsSorted(v6));
}


TEST(SortTest, BubbleSortTest)
{
    BubbleSort bs(0, NULL);
    bs.doSort();
    vect v = bs.getVect();
    EXPECT_EQ(1, v[0]);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

