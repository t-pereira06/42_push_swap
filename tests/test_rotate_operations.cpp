#include <gtest/gtest.h>

extern "C" {
    #define new dont_use_new
    #include "../libft/libft.h"
    #undef new

    #include "../includes/push_swap.h"
    // #include "rotate_operations_test.h" // use this if you create the test-only header
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

TEST(RotateOperationsTest, RA_RotatesLeftAndPrints) {
    t_stack a = make_stack({1, 2, 3, 4});

    ::testing::internal::CaptureStdout();
    ra(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    // Expected left-rotate: [2,3,4,1]
    ASSERT_EQ(a.size, 4);
    EXPECT_EQ(a.array[0], 2);
    EXPECT_EQ(a.array[1], 3);
    EXPECT_EQ(a.array[2], 4);
    EXPECT_EQ(a.array[3], 1);

    EXPECT_EQ(out, "ra\n");

    free_stack(a);
}

TEST(RotateOperationsTest, RB_RotatesLeftAndPrints) {
    t_stack b = make_stack({10, 20, 30});

    ::testing::internal::CaptureStdout();
    rb(&b);
    std::string out = ::testing::internal::GetCapturedStdout();

    // Expected left-rotate: [20,30,10]
    ASSERT_EQ(b.size, 3);
    EXPECT_EQ(b.array[0], 20);
    EXPECT_EQ(b.array[1], 30);
    EXPECT_EQ(b.array[2], 10);

    EXPECT_EQ(out, "rb\n");

    free_stack(b);
}

TEST(RotateOperationsTest, RR_CallsRAThenRBAndPrintsBoth) {
    t_stack a = make_stack({1, 2, 3});
    t_stack b = make_stack({7, 8, 9});

    ::testing::internal::CaptureStdout();
    rr(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    // A: [2,3,1], B: [8,9,7]
    ASSERT_EQ(a.size, 3);
    EXPECT_EQ(a.array[0], 2);
    EXPECT_EQ(a.array[1], 3);
    EXPECT_EQ(a.array[2], 1);

    ASSERT_EQ(b.size, 3);
    EXPECT_EQ(b.array[0], 8);
    EXPECT_EQ(b.array[1], 9);
    EXPECT_EQ(b.array[2], 7);

    // rr prints both "ra\n" then "rb\n"
    EXPECT_NE(out.find("ra\n"), std::string::npos);
    EXPECT_NE(out.find("rb\n"), std::string::npos);

    free_stack(a);
    free_stack(b);
}

TEST(RotateOperationsTest, RA_NoOpWhenSize0Or1_ButPrints) {
    // size 0
    t_stack a0 = make_stack({}, 1);
    a0.size = 0;
    ::testing::internal::CaptureStdout();
    ra(&a0);
    std::string out0 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(a0.size, 0);
    EXPECT_EQ(out0, "ra\n");
    free_stack(a0);

    // size 1
    t_stack a1 = make_stack({42});
    ::testing::internal::CaptureStdout();
    ra(&a1);
    std::string out1 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(a1.size, 1);
    EXPECT_EQ(a1.array[0], 42);
    EXPECT_EQ(out1, "ra\n");
    free_stack(a1);
}

TEST(RotateOperationsTest, RB_NoOpWhenSize0Or1_ButPrints) {
    // size 0
    t_stack b0 = make_stack({}, 1);
    b0.size = 0;
    ::testing::internal::CaptureStdout();
    rb(&b0);
    std::string out0 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(b0.size, 0);
    EXPECT_EQ(out0, "rb\n");
    free_stack(b0);

    // size 1
    t_stack b1 = make_stack({7});
    ::testing::internal::CaptureStdout();
    rb(&b1);
    std::string out1 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(b1.size, 1);
    EXPECT_EQ(b1.array[0], 7);
    EXPECT_EQ(out1, "rb\n");
    free_stack(b1);
}
