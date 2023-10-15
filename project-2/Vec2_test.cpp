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

TEST(Vec2Test, Inequality)
{
    Vec2 vec1(2, 3), vec2(3, 4);

    EXPECT_TRUE(vec1 != vec2);
}

TEST(Vec2Test, Addition)
{
    Vec2 vec1(21, 3), vec2(3, 4);

    Vec2 result = vec1 + vec2;

    EXPECT_EQ(result.x, 24);
    EXPECT_EQ(result.y, 7);
}

TEST(Vec2Test, Substraction)
{
    Vec2 vector1(3, 5), vector2(4, 5);
    Vec2 result = vector1 - vector2;

    EXPECT_EQ(result.x, -1);
    EXPECT_EQ(result.y, 0);
};

TEST(Vec2Test, Multiplication)
{
    Vec2 vec(3, 5);

    Vec2 result = vec * 4;

    EXPECT_EQ(result.x, 12);
    EXPECT_EQ(result.y, 20);
}

TEST(Vec2Test, Divition)
{
    Vec2 vec(5, 6);

    Vec2 result = vec/2;

    EXPECT_EQ(result.x, 2.5);
    EXPECT_EQ(result.y, 3);
};

TEST(Vec2Test, DestructAddition)
{
    Vec2 vec(4, 4);

    vec += Vec2 (2, 4);

    EXPECT_EQ(vec.x, 6);
    EXPECT_EQ(vec.y, 8);
};

TEST(Vec2Test, DestructSubstraction)
{
    Vec2 vec(8, 2), vector2(2, 4);
    vec -= vector2;

    EXPECT_EQ(vec.x, 6);
    EXPECT_EQ(vec.y, -2);
}

TEST(Vec2Test, DestructMultiply)
{
    Vec2 vec(2, 5);

    vec *= 10;

    EXPECT_EQ(vec.x, 20);
    EXPECT_EQ(vec.y, 50);
}

TEST(Vec2Test, DestructDivide)
{
    Vec2 vec(20.0, 5.0);

    vec /= 2;

    EXPECT_EQ(vec.x, 10);
    EXPECT_EQ(vec.y, 2.5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}