#include <gtest/gtest.h>

extern "C" {
    #define new dont_use_new
    #include "../libft/libft.h"
    #undef new

    #include "../includes/push_swap.h"
}

#include <cstdlib>
#include <initializer_list>
#include <string>

// Helpers: allocate arrays like main would
static inline void alloc_like_main(t_stack& a, t_stack& b, int cap) {
    a.size = 0; a.array = (int*)ft_calloc(cap, sizeof(int));
    b.size = 0; b.array = (int*)ft_calloc(cap, sizeof(int));
}

// ---------------- initialize_stacks ----------------
TEST(StartStacksTest, InitializeStacks_SetsZeroAndNull) {
    t_stack a;
    t_stack b;

    // Pre-set to non-zero values to ensure the function actually resets them
    a.array = reinterpret_cast<int*>(0x1);
    a.size  = 123;
    b.array = reinterpret_cast<int*>(0x2);
    b.size  = 456;

    initialize_stacks(&a, &b);

    EXPECT_EQ(a.size, 0);
    EXPECT_EQ(b.size, 0);
    EXPECT_EQ(a.array, static_cast<int*>(nullptr));
    EXPECT_EQ(b.array, static_cast<int*>(nullptr));
}


// ---------------- check_stack ----------------
TEST(StartStacksTest, CheckStack_Returns1_WhenUnique) {
    t_stack a, b;
    alloc_like_main(a, b, 4);

    // Simulate that one number already exists in A (size=1)
    a.array[0] = 7;
    a.size = 1;

    // With size=1, loop runs 0..size-2 (i<0): no check, returns 1
    EXPECT_EQ(check_stack((char*)"8", &a, &b), 1);

    free(a.array);
    free(b.array);
}

TEST(StartStacksTest, CheckStack_Duplicate_ExitsAndPrintsError) {
    t_stack a, b;
    alloc_like_main(a, b, 4);

    a.array[0] = 7; a.array[1] = 9;
    a.size = 2; // loop checks i < size-1 -> i=0 compares against 7

    // Should write "Error\n" (and "check_stack") and exit(1)
    ASSERT_DEATH(
        {
            check_stack((char*)"7", &a, &b);
        },
        "Error|check_stack"
    );
    // no frees needed; child process exits
}

// ---------------- fill_stack ----------------
TEST(StartStacksTest, FillStack_Valid_AppendsValue) {
    t_stack a, b;
    alloc_like_main(a, b, 4);

    int ret = fill_stack((char*)"42", &a, &b);

    EXPECT_EQ(ret, 1);
    EXPECT_EQ(a.size, 1);
    EXPECT_EQ(a.array[0], 42);

    free(a.array);
    free(b.array);
}

TEST(StartStacksTest, FillStack_InvalidChar_ExitsAndPrintsError) {
    t_stack a, b;
    alloc_like_main(a, b, 4);

    ASSERT_DEATH(
        {
            fill_stack((char*)"12a", &a, &b);
        },
        "Error"
    );
}

TEST(StartStacksTest, FillStack_OutOfRange_ExitsAndPrintsError) {
    t_stack a, b;
    alloc_like_main(a, b, 4);

    // 2147483648 > INT32_MAX
    ASSERT_DEATH(
        {
            fill_stack((char*)"2147483648", &a, &b);
        },
        "Error"
    );
}

// Duplicate via fill_stack path (goes through check_stack)
TEST(StartStacksTest, FillStack_Duplicate_ExitsWithCheckStackError) {
    t_stack a, b;
    alloc_like_main(a, b, 4);

    // First insert "7"
    EXPECT_EQ(fill_stack((char*)"7", &a, &b), 1);

    // Second time, duplicate triggers death via check_stack
    ASSERT_DEATH(
        {
            fill_stack((char*)"7", &a, &b);
        },
        "Error|check_stack"
    );
}

// ---------------- fill_stack_split ----------------
TEST(StartStacksTest, FillStackSplit_ParsesSpaceSeparated_AppendsAll) {
    t_stack a, b;
    alloc_like_main(a, b, 8);

    int final_size = fill_stack_split((char*)"3 1 2 -5 0", &a, &b);

    EXPECT_EQ(final_size, 5);
    EXPECT_EQ(a.size, 5);
    // Order is append order from split
    EXPECT_EQ(a.array[0], 3);
    EXPECT_EQ(a.array[1], 1);
    EXPECT_EQ(a.array[2], 2);
    EXPECT_EQ(a.array[3], -5);
    EXPECT_EQ(a.array[4], 0);

    free(a.array);
    free(b.array);
}

TEST(StartStacksTest, FillStackSplit_Duplicate_Exits) {
    t_stack a, b;
    alloc_like_main(a, b, 8);

    ASSERT_DEATH(
        {
            fill_stack_split((char*)"3 1 3", &a, &b);
        },
        "Error|check_stack"
    );
}

// ---------------- free_split (sanity) ----------------
TEST(StartStacksTest, FreeSplit_FreesAllWithoutCrash) {
    // Build a fake split like ft_split would return
    char **split = (char**)malloc(sizeof(char*) * 4);
    split[0] = (char*)malloc(2); split[0][0] = '1'; split[0][1] = '\0';
    split[1] = (char*)malloc(2); split[1][0] = '2'; split[1][1] = '\0';
    split[2] = (char*)malloc(2); split[2][0] = '3'; split[2][1] = '\0';
    split[3] = nullptr;

    // free_split takes (stack, i) where i is the number of allocated strings
    EXPECT_NO_THROW({
        free_split(split, /*i=*/3);
    });
    // cannot easily assert freed memory; absence of crash/leak is sufficient here
}
