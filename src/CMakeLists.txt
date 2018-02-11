include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(bignumber STATIC
    ./big_number.cpp
    ./big_number_integer.cpp
    ./big_number_math.cpp
    ./big_number_utils.cpp
)