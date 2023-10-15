#include "Vec2.h"
#include <gtest/gtest.h>

TEST(Vec2Test, Initialization)
{
    Vec2 myVector;

    EXPECT_EQ(myVector.x, 0);
    EXPECT_EQ(myVector.y, 0);
}

TEST(Vec2Test, Equality) 
{
    Vec2 v1(1.0, 2.0);
    Vec2 v2(1.0, 2.0);
    Vec2 v3(8.0, 8.0);
    
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v3 == v2);
}

TEST(Vec2Test, Multiplication)
{
    Vec2 vec(3, 5);

    Vec2 result = vec * 4;

    EXPECT_EQ(result.x, 12);
    EXPECT_EQ(result.y, 20);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}