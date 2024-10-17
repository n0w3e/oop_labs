#include "../include/six.h"
#include <gtest/gtest.h>

TEST(SixTest, DefaultConstructor) {
    Six expected({0});
    Six s;

    ASSERT_EQ(s, expected);
}

TEST(SixTest, CustomConstructor) {
    std::vector<unsigned char> digits = {1, 2, 3};
    Six expected(digits);
    Six s(digits);

    ASSERT_EQ(s, expected);
}

TEST(SixTest, Addition) {
    Six s1({3, 2});
    Six s2({4, 1});
    s1 += s2;

    Six expected({1, 4});
    ASSERT_EQ(s1, expected);
}

TEST(SixTest, Subtraction) {
    Six s1({5, 3});
    Six s2({2, 1});
    Six expected({3, 2});
    s1 -= s2;

    ASSERT_EQ(s1, expected);
}

TEST(SixTest, ComparisonGreater) {
    Six s1({3, 4});
    Six s2({2, 3});

    ASSERT_TRUE(s1 > s2);
}

TEST(SixTest, ComparisonLess) {
    Six s1({1, 2});
    Six s2({2, 3});

    ASSERT_TRUE(s1 < s2);
}

TEST(SixTest, ComparisonEqual) {
    Six s1({1, 2, 3});
    Six s2({1, 2, 3});

    ASSERT_TRUE(s1 == s2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}