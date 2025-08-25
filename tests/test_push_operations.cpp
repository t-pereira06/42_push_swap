#include <gtest/gtest.h>

extern "C" {
    #define new dont_use_new
    #include "../libft/libft.h"
    #undef new
    #include "../includes/push_swap.h"
    #include <stdlib.h>
}

// ---------------- Helpers ---------------- //
static t_stack make_stack(std::initializer_list<int> values, int capacity = -1) {
    t_stack stack;
    stack.size = values.size();
    int cap = (capacity == -1) ? stack.size : capacity;
    if (cap <= 0) cap = 1;
    stack.array = (int*)malloc(cap * sizeof(int));
    int i = 0;
    for (int v : values) stack.array[i++] = v;
    return stack;
}

static void free_stack(t_stack& stack) {
    free(stack.array);
    stack.array = nullptr;
    stack.size = 0;
}

// ---------------- Tests ---------------- //

TEST(PushOperationsTest, FillStackARemovesTopElementAndShifts) {
    t_stack a = make_stack({10, 20, 30}, 3);
    // No output expected from fill_stack_a
    ::testing::internal::CaptureStdout();
    fill_stack_a(&a);
    std::string out = ::testing::internal::GetCapturedStdout();
    EXPECT_TRUE(out.empty());

    EXPECT_EQ(a.size, 2);
    EXPECT_EQ(a.array[0], 20);
    EXPECT_EQ(a.array[1], 30);
    free_stack(a);
}

TEST(PushOperationsTest, FillStackBRemovesTopElementAndShifts) {
    t_stack b = make_stack({5, 15, 25}, 3);
    // No output expected from fill_stack_b
    ::testing::internal::CaptureStdout();
    fill_stack_b(&b);
    std::string out = ::testing::internal::GetCapturedStdout();
    EXPECT_TRUE(out.empty());

    EXPECT_EQ(b.size, 2);
    EXPECT_EQ(b.array[0], 15);
    EXPECT_EQ(b.array[1], 25);
    free_stack(b);
}

TEST(PushOperationsTest, PaMovesTopOfBToTopOfA_AndPrintsPa) {
    t_stack a = make_stack({100, 200}, 3);
    t_stack b = make_stack({50, 60}, 3);

    ::testing::internal::CaptureStdout();
    int ret = pa(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    // Output from ft_printf
    EXPECT_EQ(out, "pa\n");
    // Return value should be non-zero (ft_printf char count)
    EXPECT_NE(ret, 0);

    // Data changes
    EXPECT_EQ(a.size, 3);
    EXPECT_EQ(a.array[0], 50);
    EXPECT_EQ(a.array[1], 100);
    EXPECT_EQ(a.array[2], 200);

    EXPECT_EQ(b.size, 1);
    EXPECT_EQ(b.array[0], 60);

    free_stack(a);
    free_stack(b);
}

TEST(PushOperationsTest, PbMovesTopOfAToTopOfB_AndPrintsPb) {
    t_stack a = make_stack({10, 20}, 3);
    t_stack b = make_stack({30}, 3);

    ::testing::internal::CaptureStdout();
    int ret = pb(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "pb\n");
    EXPECT_NE(ret, 0);

    EXPECT_EQ(a.size, 1);
    EXPECT_EQ(a.array[0], 20);

    EXPECT_EQ(b.size, 2);
    EXPECT_EQ(b.array[0], 10);
    EXPECT_EQ(b.array[1], 30);

    free_stack(a);
    free_stack(b);
}

TEST(PushOperationsTest, PaHandlesEmptyB_NoOutputAndReturns0) {
    t_stack a = make_stack({1, 2}, 3);
    t_stack b = make_stack({}, 3);

    ::testing::internal::CaptureStdout();
    int ret = pa(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(ret, 0);
    EXPECT_TRUE(out.empty());   // should not print "pa\n"
    EXPECT_EQ(a.size, 2);
    EXPECT_EQ(b.size, 0);

    free_stack(a);
    free_stack(b);
}

TEST(PushOperationsTest, PbHandlesEmptyA_NoOutputAndReturns0) {
    t_stack a = make_stack({}, 3);
    t_stack b = make_stack({5}, 3);

    ::testing::internal::CaptureStdout();
    int ret = pb(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(ret, 0);
    EXPECT_TRUE(out.empty());   // should not print "pb\n"
    EXPECT_EQ(a.size, 0);
    EXPECT_EQ(b.size, 1);

    free_stack(a);
    free_stack(b);
}
