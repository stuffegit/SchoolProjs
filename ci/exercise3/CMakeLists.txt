cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME exercise-3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)

project(${PROJECT_NAME}   VERSION 1.0
                          DESCRIPTION "exercise3")

add_executable(greet_test greet.cpp test.cpp)
target_link_libraries(greet_test PRIVATE gtest gtest_main)

enable_testing()
add_test(NAME greet COMMAND greet_test)
