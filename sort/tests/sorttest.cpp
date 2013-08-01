#include <limits.h>
#include "../Bubble.h"
#include "gtest/gtest.h"

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

