#include <gtest/gtest.h>
#include "../count.h"

TEST(CountOnesTest1, Range2To7) {
    int a = 2;
    int b = 7;
    int result = count_one_in_range(a, b);
    ASSERT_TRUE(result == 11);
}

TEST(CountOnesTest2, Range0To0) {
    int a = 0;
    int b = 0;
    int result = count_one_in_range(a, b);
    ASSERT_TRUE(result == 0);
}

TEST(CountOnesTest3, Range1To1) {
    int a = 1;
    int b = 1;
    int result = count_one_in_range(a, b);
    ASSERT_TRUE(result == 1);
}

TEST(CountOnesTest4, Range5To10) {
    int a = 5;
    int b = 10;
    int result = count_one_in_range(a, b);
    ASSERT_TRUE(result == 12);
}

TEST(CountOnesTest5, Range15To20) {
    int a = 15;
    int b = 20;
    int result = count_one_in_range(a, b);
    ASSERT_TRUE(result == 14);
}

TEST(CountOnesTest6, Range0To1) {
    int a = 0;
    int b = 1;
    int result = count_one_in_range(a, b);
    ASSERT_TRUE(result == 1);
}

// Функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();               
}