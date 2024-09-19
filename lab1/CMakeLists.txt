cmake_minimum_required(VERSION 3.30)

project(ONES)

# Подключение Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

add_executable(ONES count.cpp main.cpp)

#Создание тестов
enable_testing()
add_executable(Tests tests/test.cpp count.cpp)
target_link_libraries(Tests gtest_main)

add_test(NAME CountOnesTests COMMAND tests)
