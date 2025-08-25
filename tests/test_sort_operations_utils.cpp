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

/*
 op_3:
   rra; pa; ra; ra
 Scenario: insert between a[1] and a[2].
 A=[10,20,30], B=[25] → final A=[10,20,25,30]
*/
TEST(SortOperationsUtilsTest, Op3_RraPaRaRa_PrintsSequence_AndInsertsMiddle) {
    t_stack a = make_stack({10,20,30}, 4);
    t_stack b = make_stack({25}, 1);

    ::testing::internal::CaptureStdout();
    op_3(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "rra\npa\nra\nra\n");

    ASSERT_EQ(a.size, 4);
    EXPECT_TRUE(stack_is_sorted(&a));
    EXPECT_EQ(a.array[0], 10);
    EXPECT_EQ(a.array[1], 20);
    EXPECT_EQ(a.array[2], 25);
    EXPECT_EQ(a.array[3], 30);

    EXPECT_EQ(b.size, 0);

    free_stack(a);
    free_stack(b);
}

/*
 op_4:
   rra; rra; pa; ra; ra; ra
 Scenario: insert near the front (between a[0] and a[1]).
 A=[10,20,30], B=[15] → final A=[10,15,20,30]
*/
TEST(SortOperationsUtilsTest, Op4_RraRraPaRaRaRa_PrintsSequence_AndInsertsNearFront) {
    t_stack a = make_stack({10,20,30}, 4);
    t_stack b = make_stack({15}, 1);

    ::testing::internal::CaptureStdout();
    op_4(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "rra\nrra\npa\nra\nra\nra\n");

    ASSERT_EQ(a.size, 4);
    EXPECT_TRUE(stack_is_sorted(&a));
    EXPECT_EQ(a.array[0], 10);
    EXPECT_EQ(a.array[1], 15);
    EXPECT_EQ(a.array[2], 20);
    EXPECT_EQ(a.array[3], 30);

    EXPECT_EQ(b.size, 0);

    free_stack(a);
    free_stack(b);
}

/*
 op_5:
   rra; pa; ra; ra
 Scenario: insert between a[1] and a[2].
 A=[10,20,30], B=[25] → final A=[10,20,25,30]
*/
TEST(SortOperationsUtilsTest, Op5_RraPaRaRa_PrintsSequence_AndInsertsBetweenA1AndA2) {
    // Precondition for op_5: b0 > a1 && b0 < a2  (with zero-based indexes a[1], a[2])
    // A = [10,20,30], choose b0 = 25  -> should end up [10,20,25,30]
    t_stack a = make_stack({10, 20, 30}, 4);
    t_stack b = make_stack({25}, 1);

    ::testing::internal::CaptureStdout();
    op_5(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    // Exact command sequence
    EXPECT_EQ(out, "rra\npa\nra\nra\n");

    // Final state
    ASSERT_EQ(a.size, 4);
    EXPECT_EQ(b.size, 0);
    EXPECT_TRUE(stack_is_sorted(&a));
    EXPECT_EQ(a.array[0], 10);
    EXPECT_EQ(a.array[1], 20);
    EXPECT_EQ(a.array[2], 25);
    EXPECT_EQ(a.array[3], 30);

    free_stack(a);
    free_stack(b);
}

/*
 op_6:
   pa; ra
 Scenario: insert at end.
 A=[10,20,30], B=[40] → after op_6 A=[10,20,30,40], B=[]
*/
TEST(SortOperationsUtilsTest, Op6_PushAndRotate_PrintsPaRa_AndInsertsAtEnd) {
    t_stack a = make_stack({10,20,30}, 4);
    t_stack b = make_stack({40}, 1);

    ::testing::internal::CaptureStdout();
    op_6(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "pa\nra\n");

    ASSERT_EQ(a.size, 4);
    EXPECT_TRUE(stack_is_sorted(&a));
    EXPECT_EQ(a.array[0], 10);
    EXPECT_EQ(a.array[1], 20);
    EXPECT_EQ(a.array[2], 30);
    EXPECT_EQ(a.array[3], 40);

    EXPECT_EQ(b.size, 0);

    free_stack(a);
    free_stack(b);
}
