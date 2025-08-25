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

TEST(SwapOperationsTest, SA_SwapsFirstTwoAndPrints) {
    t_stack a = make_stack({10, 20, 30});

    ::testing::internal::CaptureStdout();
    sa(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "sa\n");
    ASSERT_EQ(a.size, 3);
    EXPECT_EQ(a.array[0], 20);
    EXPECT_EQ(a.array[1], 10);
    EXPECT_EQ(a.array[2], 30);

    free_stack(a);
}

TEST(SwapOperationsTest, SB_SwapsFirstTwoAndPrints) {
    t_stack b = make_stack({7, 9, 11});

    ::testing::internal::CaptureStdout();
    sb(&b);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "sb\n");
    ASSERT_EQ(b.size, 3);
    EXPECT_EQ(b.array[0], 9);
    EXPECT_EQ(b.array[1], 7);
    EXPECT_EQ(b.array[2], 11);

    free_stack(b);
}

TEST(SwapOperationsTest, SA_NoOpWhenSize0Or1_ButPrints) {
    // size 0
    t_stack a0 = make_stack({}, 1);
    a0.size = 0;
    ::testing::internal::CaptureStdout();
    sa(&a0);
    std::string out0 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(out0, "sa\n");
    EXPECT_EQ(a0.size, 0);
    free_stack(a0);

    // size 1
    t_stack a1 = make_stack({42});
    ::testing::internal::CaptureStdout();
    sa(&a1);
    std::string out1 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(out1, "sa\n");
    EXPECT_EQ(a1.size, 1);
    EXPECT_EQ(a1.array[0], 42);
    free_stack(a1);
}

TEST(SwapOperationsTest, SB_NoOpWhenSize0Or1_ButPrints) {
    // size 0
    t_stack b0 = make_stack({}, 1);
    b0.size = 0;
    ::testing::internal::CaptureStdout();
    sb(&b0);
    std::string out0 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(out0, "sb\n");
    EXPECT_EQ(b0.size, 0);
    free_stack(b0);

    // size 1
    t_stack b1 = make_stack({99});
    ::testing::internal::CaptureStdout();
    sb(&b1);
    std::string out1 = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(out1, "sb\n");
    EXPECT_EQ(b1.size, 1);
    EXPECT_EQ(b1.array[0], 99);
    free_stack(b1);
}

TEST(SwapOperationsTest, SS_CallsSAThenSB_PrintsBothAndSwapsBoth) {
    t_stack a = make_stack({1, 2, 3});
    t_stack b = make_stack({4, 5, 6});

    ::testing::internal::CaptureStdout();
    ss(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    // ss calls sa then sb → output includes both
    EXPECT_NE(out.find("sa\n"), std::string::npos);
    EXPECT_NE(out.find("sb\n"), std::string::npos);

    ASSERT_EQ(a.size, 3);
    EXPECT_EQ(a.array[0], 2);
    EXPECT_EQ(a.array[1], 1);
    EXPECT_EQ(a.array[2], 3);

    ASSERT_EQ(b.size, 3);
    EXPECT_EQ(b.array[0], 5);
    EXPECT_EQ(b.array[1], 4);
    EXPECT_EQ(b.array[2], 6);

    free_stack(a);
    free_stack(b);
}
