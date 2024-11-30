cmake_minimum_required(VERSION 3.10)

project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_library(MAIN main.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(lab4_tests tests/lab4_tests.cpp)
target_link_libraries(lab4_tests MAIN gtest_main)

enable_testing()
add_test(NAME lab4_tests COMMAND lab4_tests)