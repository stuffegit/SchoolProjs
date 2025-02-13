cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME exercise-8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)

project(${PROJECT_NAME}   VERSION 1.0
                          DESCRIPTION "exercise-8")

add_executable(queue_test test.cpp)
target_link_libraries(queue_test PRIVATE gtest gmock) 

enable_testing()
add_test(NAME queue_test COMMAND queue_test)