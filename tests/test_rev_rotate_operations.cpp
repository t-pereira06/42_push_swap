#include <gtest/gtest.h>

extern "C" {
    // avoid C++ keyword clash in libft (param named `new`)
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

TEST(RevRotateOperationsTest, RRA_MovesLastToFront_Normal) {
    t_stack a = make_stack({1, 2, 3, 4});

    ::testing::internal::CaptureStdout();
    rra(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    // Data order
    ASSERT_EQ(a.size, 4);
    EXPECT_EQ(a.array[0], 4);
    EXPECT_EQ(a.array[1], 1);
    EXPECT_EQ(a.array[2], 2);
    EXPECT_EQ(a.array[3], 3);

    // Printed op
    EXPECT_NE(out.find("rra\n"), std::string::npos);

    free_stack(a);
}

TEST(RevRotateOperationsTest, RRB_MovesLastToFront_Normal) {
    t_stack b = make_stack({10, 20, 30});

    ::testing::internal::CaptureStdout();
    rrb(&b);
    std::string out = ::testing::internal::GetCapturedStdout();

    ASSERT_EQ(b.size, 3);
    EXPECT_EQ(b.array[0], 30);
    EXPECT_EQ(b.array[1], 10);
    EXPECT_EQ(b.array[2], 20);

    EXPECT_NE(out.find("rrb\n"), std::string::npos);

    free_stack(b);
}

TEST(RevRotateOperationsTest, RRR_AppliesRRAAndRRB) {
    t_stack a = make_stack({1, 2, 3});
    t_stack b = make_stack({7, 8, 9});

    ::testing::internal::CaptureStdout();
    rrr(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    ASSERT_EQ(a.size, 3);
    EXPECT_EQ(a.array[0], 3);
    EXPECT_EQ(a.array[1], 1);
    EXPECT_EQ(a.array[2], 2);

    ASSERT_EQ(b.size, 3);
    EXPECT_EQ(b.array[0], 9);
    EXPECT_EQ(b.array[1], 7);
    EXPECT_EQ(b.array[2], 8);

    // rrr calls rra then rrb, so we expect both prints
    EXPECT_NE(out.find("rra\n"), std::string::npos);
    EXPECT_NE(out.find("rrb\n"), std::string::npos);

    free_stack(a);
    free_stack(b);
}

TEST(RevRotateOperationsTest, RRA_NoOp_WhenSize0) {
    t_stack a = make_stack({}, 1);  // size 0, capacity 1
    a.size = 0;

    ::testing::internal::CaptureStdout();
    rra(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    // unchanged
    EXPECT_EQ(a.size, 0);
    // still prints the op
    EXPECT_NE(out.find("rra\n"), std::string::npos);

    free_stack(a);
}

TEST(RevRotateOperationsTest, RRA_NoOp_WhenSize1) {
    t_stack a = make_stack({42});

    ::testing::internal::CaptureStdout();
    rra(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(a.size, 1);
    EXPECT_EQ(a.array[0], 42);
    EXPECT_NE(out.find("rra\n"), std::string::npos);

    free_stack(a);
}

TEST(RevRotateOperationsTest, RRB_NoOp_WhenSize0Or1) {
    // size 0
    t_stack b0 = make_stack({}, 1);
    b0.size = 0;
    ::testing::internal::CaptureStdout();
    rrb(&b0);
    std::string out0 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(b0.size, 0);
    EXPECT_NE(out0.find("rrb\n"), std::string::npos);
    free_stack(b0);

    // size 1
    t_stack b1 = make_stack({7});
    ::testing::internal::CaptureStdout();
    rrb(&b1);
    std::string out1 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(b1.size, 1);
    EXPECT_EQ(b1.array[0], 7);
    EXPECT_NE(out1.find("rrb\n"), std::string::npos);
    free_stack(b1);
}
