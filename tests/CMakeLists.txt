include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_executable(test_bigint
    ./test_bigint.cpp
)

target_link_libraries(test_bigint
    bigint
)