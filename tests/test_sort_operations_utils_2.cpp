#include <gtest/gtest.h>

extern "C" {
    #define new dont_use_new
    #include "../libft/libft.h"
    #undef new

    #include "../includes/push_swap.h"
}

#include <initializer_list>
#include <cstdlib>
#include <string>

// ---------- Helpers ----------
static inline t_stack make_stack(std::initializer_list<int> values, int capacity = -1) {
    t_stack s;
    s.size = static_cast<int>(values.size());
    int cap = (capacity == -1) ? s.size : capacity;
    if (cap <= 0) cap = 1;
    s.array = (int*)malloc(sizeof(int) * cap);
    int i = 0;
    for (int v : values) s.array[i++] = v;
    return s;
}
static inline void free_stack(t_stack& s) {
    free(s.array);
    s.array = nullptr;
    s.size = 0;
}

// ---------- Tests ----------

// pass_numbers_to_a: should do 'size_b' pushes, printing "pa\n" that many times,
// and move all elements from B to A. Note that consecutive 'pa' will reverse B's order on A.
TEST(SortNumbersUtils2Test, PassNumbersToA_PushesAllFromBToA_PrintsPaTimesN) {
    // Start with A empty, B = [1,2,3] (top=1)
    t_stack a = make_stack({}, 6);
    t_stack b = make_stack({1, 2, 3}, 6);

    ::testing::internal::CaptureStdout();
    pass_numbers_to_a(&a, &b, b.size);
    std::string out = ::testing::internal::GetCapturedStdout();

    // Expect three "pa\n"
    EXPECT_EQ(out, std::string("pa\npa\npa\n"));

    // B becomes empty, A grows to 3. With consecutive pa, A ends up [3,2,1]
    ASSERT_EQ(a.size, 3);
    EXPECT_EQ(b.size, 0);
    EXPECT_EQ(a.array[0], 3);
    EXPECT_EQ(a.array[1], 2);
    EXPECT_EQ(a.array[2], 1);

    free_stack(a);
    free_stack(b);
}

// check_bit: when bit i of A.top is 0 -> pb (prints "pb\n", moves top to B);
// otherwise -> ra (prints "ra\n", rotates A left).
TEST(SortNumbersUtils2Test, CheckBit_PushesWhenZeroBit_PrintsPb) {
    // A.top = 4 (0b100), for i=0 bit is 0 -> pb
    t_stack a = make_stack({4, 9, 8});
    t_stack b = make_stack({}, 3);

    ::testing::internal::CaptureStdout();
    check_bit(&a, &b, 0);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "pb\n");
    EXPECT_EQ(a.size, 2);
    EXPECT_EQ(b.size, 1);
    EXPECT_EQ(b.array[0], 4);  // moved top

    free_stack(a);
    free_stack(b);
}

TEST(SortNumbersUtils2Test, CheckBit_RotatesWhenOneBit_PrintsRa) {
    // A.top = 5 (0b101), for i=0 bit is 1 -> ra
    t_stack a = make_stack({5, 6, 7});
    t_stack b = make_stack({}, 3);

    ::testing::internal::CaptureStdout();
    check_bit(&a, &b, 0);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "ra\n");
    // A rotated left: [6,7,5]
    ASSERT_EQ(a.size, 3);
    EXPECT_EQ(a.array[0], 6);
    EXPECT_EQ(a.array[1], 7);
    EXPECT_EQ(a.array[2], 5);
    // B unchanged
    EXPECT_EQ(b.size, 0);

    free_stack(a);
    free_stack(b);
}

// do_sort: radix-style bit passes; expects values are already indexed [0..n-1].
// After do_sort, A should be sorted ascending and B empty. Also, some output must be printed.
TEST(SortNumbersUtils2Test, DoSort_SortsIndexedArrayAscending_PrintsOps) {
    // Unsorted but indexed values (typical precondition after convert_to_index)
    // Max value = 3 -> max_bits can be 2 (bits 0..2 checked inclusive as per code)
    t_stack a = make_stack({3, 0, 2, 1});
    t_stack b = make_stack({}, 4);

    ::testing::internal::CaptureStdout();
    do_sort(&a, &b, /*max_bits=*/2);
    std::string out = ::testing::internal::GetCapturedStdout();

    // Sorted ascending, B empty
    ASSERT_EQ(a.size, 4);
    EXPECT_TRUE(stack_is_sorted(&a));
    EXPECT_EQ(b.size, 0);

    // Some combination of pb/ra/pa must have been printed
    EXPECT_FALSE(out.empty());

    EXPECT_EQ(a.array[0], 0);
    EXPECT_EQ(a.array[1], 1);
    EXPECT_EQ(a.array[2], 2);
    EXPECT_EQ(a.array[3], 3);

    free_stack(a);
    free_stack(b);
}
