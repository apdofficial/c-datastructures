cmake_minimum_required(VERSION 3.13.0)
project(data_structures VERSION 0.1)

enable_testing()

add_executable(data_structures_example example.c)
target_link_libraries(data_structures_example PRIVATE data_structures_lib)

include_directories(utest.h)

add_subdirectory(src)
add_subdirectory(tests)

