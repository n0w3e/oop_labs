cmake_minimum_required(VERSION 3.10)

project(ConvexFigures)

set(CMAKE_CXX_STANDARD 11)

add_library(FigureLib 
    src/Triangle.cpp 
    src/Square.cpp 
    src/Rectangle.cpp 
    src/Array.cpp
)

add_executable(FigureApp main.cpp)
target_link_libraries(FigureApp FigureLib)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(FigureTests tests/figure_tests.cpp)
target_link_libraries(FigureTests FigureLib gtest_main)

enable_testing()
add_test(NAME FigureTests COMMAND FigureTests)
