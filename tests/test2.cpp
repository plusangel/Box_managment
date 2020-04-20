#include <iostream>

#include "gtest/gtest.h"
#include "Box.h"

TEST(box_test, box_addition)
{
    Box sumBox {1, 1, 2};
    Box aBox {1, 1, 1};

    EXPECT_EQ(sumBox, aBox+aBox);
}

TEST(box_test, box_prefix_incement)
{
    Box aBox {1, 1, 1,};
    Box result {2, 2, 2};

    EXPECT_EQ(++aBox, result);
}

