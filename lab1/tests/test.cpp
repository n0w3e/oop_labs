#include <gtest/gtest.h>
#include "../count.h"

TEST(CountOnesTest1, Range2To7) {
    EXPECT_EQ(count_one_in_range(2, 7), 11);
}

TEST(CountOnesTest2, Range0To0) {
    EXPECT_EQ(count_one_in_range(0, 0), 0);
}

TEST(CountOnesTest3, Range1To1) {
    EXPECT_EQ(count_one_in_range(1, 1), 1);
}

TEST(CountOnesTest4, Range5To10) {
    EXPECT_EQ(count_one_in_range(5, 10), 12);
}

TEST(CountOnesTest5, Range15To20) {
    EXPECT_EQ(count_one_in_range(15, 20), 14);
}

TEST(CountOnesTest6, Range0To1) {
    EXPECT_EQ(count_one_in_range(0, 1), 1);
}

// Функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();               
}