cmake_minimum_required(VERSION 2.8)

project(big-number CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O2")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_library(bignumber STATIC
    ./src/big_number.cpp
    ./src/big_number_integer.cpp
    ./src/big_number_math.cpp
    ./src/big_number_utils.cpp
)

add_subdirectory(test)