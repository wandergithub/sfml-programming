#include "Vec2.h"
#include <gtest/gtest.h>


TEST(Vec2Test, Equality) {
    Vec2 v1(1.0, 2.0);
    Vec2 v2(1.0, 2.0);
    
    EXPECT_TRUE(v1 == v2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}