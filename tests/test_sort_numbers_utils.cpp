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

// ---------------- Helpers ----------------
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

/* extern "C" {
    // from indexing.c
    int stack_is_sorted(t_stack *stack_a);
} */

// ---------------- Tests ----------------

/* op_1: should call pa() only and print "pa\n" once. */
TEST(SortNumbersUtilsTest, Op1_PushesFromBToA_PrintsPa) {
    // A initially [10,20], B top=5
    t_stack a = make_stack({10, 20}, 3);
    t_stack b = make_stack({5}, 3);

    ::testing::internal::CaptureStdout();
    op_1(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "pa\n");

    // After pa: A = [5,10,20], B empty
    ASSERT_EQ(a.size, 3);
    EXPECT_EQ(a.array[0], 5);
    EXPECT_EQ(a.array[1], 10);
    EXPECT_EQ(a.array[2], 20);

    EXPECT_EQ(b.size, 0);

    free_stack(a);
    free_stack(b);
}

/* op_2: should call pa() then sa(), printing "pa\nsa\n" (in that order). */
TEST(SortNumbersUtilsTest, Op2_PushesAndSwaps_PrintsPaThenSa) {
    // A [10,20], B top=15 -> pa: [15,10,20], sa -> [10,15,20]
    t_stack a = make_stack({10, 20}, 3);
    t_stack b = make_stack({15}, 3);

    ::testing::internal::CaptureStdout();
    op_2(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "pa\nsa\n");

    ASSERT_EQ(a.size, 3);
    EXPECT_EQ(a.array[0], 10);
    EXPECT_EQ(a.array[1], 15);
    EXPECT_EQ(a.array[2], 20);

    EXPECT_EQ(b.size, 0);

    free_stack(a);
    free_stack(b);
}

/* operations(): case that results in op_1 twice (both b[0] < a[0] on each iteration). */
TEST(SortNumbersUtilsTest, Operations_Op1ThenOp1_PrintsPaPa_AndSorted) {
    // A starts with three (already sorted), B has two smaller values
    // After two op_1 insertions, A should contain all five values in sorted order.
    t_stack a = make_stack({10, 20, 30}, 5);
    t_stack b = make_stack({1, 0}, 5);

    ::testing::internal::CaptureStdout();
    operations(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    // Exactly two pushes from B to A
    EXPECT_EQ(out, "pa\npa\n");

    // Sizes
    EXPECT_EQ(a.size, 5);
    EXPECT_EQ(b.size, 0);

    // Final A is sorted
    EXPECT_TRUE(stack_is_sorted(&a));

    // And it contains the right values (order already checked by sortedness)
    // 0,1,10,20,30
    EXPECT_EQ(a.array[0], 0);
    EXPECT_EQ(a.array[1], 1);
    EXPECT_EQ(a.array[2], 10);
    EXPECT_EQ(a.array[3], 20);
    EXPECT_EQ(a.array[4], 30);

    free_stack(a);
    free_stack(b);
}

/* operations(): case that results in op_1 then op_2, which is the usual insert pattern
   when A starts sorted and B has two increasing elements smaller than A[1]. */
TEST(SortNumbersUtilsTest, Operations_Op1ThenOp2_PrintsPaPaSa_AndSorted) {
    // A sorted [5,10,15], B [1,2]
    // Iter1: b0(1) < a0(5) -> op_1 -> pa => A [1,5,10,15], B [2]
    // Iter2: b0(2) in (a0=1, a1=5) -> op_2 -> pa; sa => A [1,2,5,10,15]
    t_stack a = make_stack({5, 10, 15}, 5);
    t_stack b = make_stack({1, 2}, 5);

    ::testing::internal::CaptureStdout();
    operations(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    // Expect "pa\n" (op_1), then "pa\nsa\n" (op_2) → total "pa\npa\nsa\n"
    EXPECT_EQ(out, "pa\npa\nsa\n");

    ASSERT_EQ(a.size, 5);
    EXPECT_TRUE(stack_is_sorted(&a));
    EXPECT_EQ(b.size, 0);

    free_stack(a);
    free_stack(b);
}
