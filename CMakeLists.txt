cmake_minimum_required(VERSION 3.10)
project(push_swap C CXX)

option(COVERAGE "Enable coverage flags" ON)

if(COVERAGE)
  # Compile with no optimizations + coverage
  add_compile_options(-O0 -g --coverage)
  add_link_options(--coverage)
endif()

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Include headers (both push_swap and libft headers)
include_directories(include libft)

# Build your push_swap library (all C files you want to test)
add_library(push_swap
    srcs/indexing.c
    srcs/push_operations.c
    srcs/push_swap.c
    srcs/rev_rotate_operations.c
    srcs/rotate_operations.c
    srcs/sort_numbers_utils.c
    srcs/sort_operations_utils_2.c
    srcs/sort_operations_utils.c
    srcs/sort_operations.c
    srcs/start_stacks.c
    srcs/swap_operations.c
)

# GoogleTest
enable_testing()
find_package(GTest REQUIRED)

# Test executable (all test .cpp files together)
add_executable(test_suite
    tests/test_indexing.cpp
    tests/test_push_operations.cpp
    tests/test_rev_rotate_operations.cpp
    tests/test_rotate_operations.cpp
    tests/test_sort_numbers_utils.cpp
    tests/test_sort_operations_utils_2.cpp
    tests/test_sort_operations_utils.cpp
    tests/test_sort_operations.cpp
    tests/test_start_stacks.cpp
    tests/test_swap_operations.cpp
)

# Link push_swap, libft.a, and gtest
target_link_libraries(test_suite
    push_swap
    ${CMAKE_SOURCE_DIR}/libft/libft.a
    GTest::gtest
    pthread
)

add_test(NAME test_suite COMMAND test_suite)
