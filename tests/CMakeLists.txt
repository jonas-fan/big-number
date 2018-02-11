include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_executable(test_big_number
    ./test_big_number.cpp
)

target_link_libraries(test_big_number
    bignumber
)