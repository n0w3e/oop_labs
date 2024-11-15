cmake_minimum_required(VERSION 3.10)

project(Figures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(FigureLib 
    src/Triangle.cpp 
    src/Square.cpp 
    src/Rectangle.cpp 
    src/Array.cpp
    src/Point.cpp
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

add_executable(FigureTests tests/lab4_tests.cpp)
target_link_libraries(FigureTests FigureLib gtest_main)

enable_testing()
add_test(NAME FigureTests COMMAND FigureTests)
