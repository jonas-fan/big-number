cmake_minimum_required(VERSION 2.8)

project(big-number-test CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O2")

include_directories(
    ${CMAKE_SOURCE_DIR}/include/
)

add_executable(test
    ./test.cpp
)

target_link_libraries(test
    bignumber
)