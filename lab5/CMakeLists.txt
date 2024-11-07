cmake_minimum_required(VERSION 3.10)

project(lab5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(SRC src/memory_resource.cpp)

add_executable(MAIN main.cpp)
target_link_libraries(MAIN SRC)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(lab5_tests tests/lab5_tests.cpp)
target_link_libraries(lab5_tests SRC gtest_main)

enable_testing()
add_test(NAME lab5_tests COMMAND lab5_tests)
