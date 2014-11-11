cmake_minimum_required(VERSION 2.8)

project(big-number C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O2")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_library(bignumber STATIC
    ./src/big_number.c
    ./src/big_number_type.c
    ./src/big_number_operator.c
)

add_subdirectory(test)