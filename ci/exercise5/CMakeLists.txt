cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME exercise-5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)

project(${PROJECT_NAME}   VERSION 1.0
                          DESCRIPTION "exercise5")

add_executable(queue_test queue.cpp test.cpp)
target_link_libraries(queue_test PRIVATE gtest gtest_main)

enable_testing()
add_test(NAME queue COMMAND queue_test)
