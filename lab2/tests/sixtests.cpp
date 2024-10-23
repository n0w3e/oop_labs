#include "../include/six.h"
#include <gtest/gtest.h>

TEST(SixTest, DefaultConstructor) {
    unsigned char default_digits[] = {0}; 
    Six expected(default_digits, 1);
    Six s;

    ASSERT_EQ(s, expected);
}

TEST(SixTest, CustomConstructor) {
    unsigned char digits[] = {1, 2, 3};
    Six expected(digits, 3);
    Six s(digits, 3);

    ASSERT_EQ(s, expected);
}

TEST(SixTest, Addition) {
    unsigned char digits1[] = {3, 2};
    unsigned char digits2[] = {4, 1};
    Six s1(digits1, 2);
    Six s2(digits2, 2);
    s1 += s2;

    unsigned char expectedDigits[] = {1, 4};
    Six expected(expectedDigits, 2);
    ASSERT_EQ(s1, expected);
}

TEST(SixTest, Subtraction) {
    unsigned char digits1[] = {5, 3};
    unsigned char digits2[] = {2, 1};
    Six s1(digits1, 2);
    Six s2(digits2, 2);

    unsigned char expectedDigits[] = {3, 2};
    Six expected(expectedDigits, 2);

    s1 -= s2;
    ASSERT_EQ(s1, expected);
}

TEST(SixTest, ComparisonGreater) {
    unsigned char digits1[] = {3, 4};
    unsigned char digits2[] = {2, 3};
    Six s1(digits1, 2);
    Six s2(digits2, 2);

    ASSERT_TRUE(s1 > s2);
}

TEST(SixTest, ComparisonLess) {
    unsigned char digits1[] = {1, 2};
    unsigned char digits2[] = {2, 3};
    Six s1(digits1, 2);
    Six s2(digits2, 2);

    ASSERT_TRUE(s1 < s2);
}

TEST(SixTest, ComparisonEqual) {
    unsigned char digits1[] = {1, 2, 3};
    unsigned char digits2[] = {1, 2, 3};
    Six s1(digits1, 3);
    Six s2(digits2, 3);

    ASSERT_TRUE(s1 == s2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
