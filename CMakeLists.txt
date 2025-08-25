cmake_minimum_required(VERSION 3.10)
project(push_swap C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

option(COVERAGE "Enable coverage flags" ON)

# Include headers
include_directories(include libft)

# ---- Library with code under test (NO main here) ----
add_library(push_swap
    srcs/indexing.c
    srcs/push_operations.c
    srcs/rev_rotate_operations.c
    srcs/rotate_operations.c
    srcs/sort_numbers_utils.c
    srcs/sort_operations_utils_2.c
    srcs/sort_operations_utils.c
    srcs/sort_operations.c
    srcs/start_stacks.c
    srcs/swap_operations.c
)
# If you want the real program too (optional):
# add_executable(push_swap_bin srcs/push_swap.c)
# target_link_libraries(push_swap_bin push_swap ${CMAKE_SOURCE_DIR}/libft/libft.a)

# ---- GoogleTest ----
enable_testing()
find_package(GTest REQUIRED)

# ---- Tests executable ----
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

target_link_libraries(test_suite
    push_swap
    ${CMAKE_SOURCE_DIR}/libft/libft.a
    GTest::gtest          # you wrote your own main in tests; keep gtest only
    pthread
)

# ---- Coverage flags (apply AFTER targets are defined) ----
if(COVERAGE)
  target_compile_options(push_swap PRIVATE -O0 -g --coverage)
  target_link_options(push_swap PRIVATE --coverage)
  target_compile_options(test_suite PRIVATE -O0 -g --coverage)
  target_link_options(test_suite PRIVATE --coverage)
endif()

add_test(NAME test_suite COMMAND test_suite)
