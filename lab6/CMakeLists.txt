cmake_minimum_required(VERSION 3.10)

project(lab6)

set(CMAKE_CXX_STANDARD 17)

add_library(SRC src/BattleVisitor.cpp src/DungeonEditor.cpp src/Logger.cpp src/NPC.cpp src/Observers.cpp src/NPCFactory.cpp)

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

add_executable(lab6_tests tests/lab6_tests.cpp)
target_link_libraries(lab6_tests SRC gtest_main)

enable_testing()
add_test(NAME lab6_tests COMMAND lab6_tests)
