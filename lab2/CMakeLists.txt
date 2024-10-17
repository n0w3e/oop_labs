cmake_minimum_required(VERSION 3.30)

project(SixProject)

set(CMAKE_CXX_STANDARD 17)

add_library(SixLib src/six.cpp)

add_executable(Six src/main.cpp)
target_link_libraries(Six SixLib)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

add_executable(SixTests tests/sixtests.cpp)
target_link_libraries(SixTests SixLib gtest_main)

enable_testing()
add_test(NAME SixTests COMMAND SixTests)