cmake_minimum_required(VERSION 3.10)

project(lab7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_library(SRC src/BattleVisitor.cpp src/DungeonEditor.cpp src/Logger.cpp src/NPC.cpp src/NPCFactory.cpp src/Observers.cpp)

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

add_executable(lab7_tests tests/lab7_tests.cpp)
target_link_libraries(lab7_tests SRC gtest_main)

enable_testing()
add_test(NAME lab7_tests COMMAND lab7_tests)
