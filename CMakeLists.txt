cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME large_number)
set(PROGRAM_NAME large_number)
set(LANGUAGE CXX)

set(CXX_FALGS "-O2 -Wall -g -std=c++11")

set(INCLUDES ${CMAKE_SOURCE_DIR}/include)
set(SRCS src/main.cpp src/math.cpp src/number.cpp src/number_type.cpp)

project(${PROJECT_NAME} ${LANGUAGE})

set(CMAKE_C_FLAGS ${C_FLAGS})

include_directories(${INCLUDES})

add_executable(${PROGRAM_NAME} ${SRCS})