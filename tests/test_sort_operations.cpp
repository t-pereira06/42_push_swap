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

// ---------- sort_2_numbers ----------
TEST(SortOperationsTest, Sort2Numbers_SwapsWhenNeeded_PrintsSa) {
    t_stack a = make_stack({2, 1});
    ::testing::internal::CaptureStdout();
    sort_2_numbers(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "sa\n");
    ASSERT_EQ(a.size, 2);
    EXPECT_EQ(a.array[0], 1);
    EXPECT_EQ(a.array[1], 2);
    free_stack(a);
}

TEST(SortOperationsTest, Sort2Numbers_NoSwapWhenSorted_NoOutput) {
    t_stack a = make_stack({1, 2});
    ::testing::internal::CaptureStdout();
    sort_2_numbers(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_TRUE(out.empty());
    EXPECT_EQ(a.array[0], 1);
    EXPECT_EQ(a.array[1], 2);
    free_stack(a);
}

// ---------- sort_3_numbers ----------

TEST(SortOperationsTest, Sort3Numbers_Case_sa) {
    // (a0 > a1) && (a0 < a2) -> sa
    t_stack a = make_stack({2, 1, 3});
    ::testing::internal::CaptureStdout();
    sort_3_numbers(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "sa\n");
    EXPECT_TRUE(stack_is_sorted(&a));
    free_stack(a);
}

TEST(SortOperationsTest, Sort3Numbers_Case_ra) {
    // (a0 > a1) && (a0 > a2) && (a1 < a2) -> ra
    t_stack a = make_stack({3, 1, 2});
    ::testing::internal::CaptureStdout();
    sort_3_numbers(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "ra\n");
    EXPECT_TRUE(stack_is_sorted(&a));
    free_stack(a);
}

TEST(SortOperationsTest, Sort3Numbers_Case_rra) {
    // (a2 < a1) && (a1 > a0) && (a0 > a2) -> rra
    t_stack a = make_stack({2, 3, 1});
    ::testing::internal::CaptureStdout();
    sort_3_numbers(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "rra\n");
    EXPECT_TRUE(stack_is_sorted(&a));
    free_stack(a);
}

TEST(SortOperationsTest, Sort3Numbers_Case_sa_rra) {
    // (a0 > a1) && (a1 > a2) -> sa; rra
    t_stack a = make_stack({3, 2, 1});
    ::testing::internal::CaptureStdout();
    sort_3_numbers(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "sa\nrra\n");
    EXPECT_TRUE(stack_is_sorted(&a));
    free_stack(a);
}

TEST(SortOperationsTest, Sort3Numbers_Case_sa_ra) {
    // (a1 > a0) && (a1 > a2) && (a0 < a2) -> sa; ra
    t_stack a = make_stack({1, 3, 2});
    ::testing::internal::CaptureStdout();
    sort_3_numbers(&a);
    std::string out = ::testing::internal::GetCapturedStdout();

    EXPECT_EQ(out, "sa\nra\n");
    EXPECT_TRUE(stack_is_sorted(&a));
    free_stack(a);
}

// ---------- sort_5_numbers ----------

TEST(SortOperationsTest, Sort5Numbers_SortsAscending_BEmpty_ContainsTwoPbAndSomePa) {
    // Typical unsorted small set
    t_stack a = make_stack({4, 1, 3, 0, 2}, 5);
    t_stack b = make_stack({}, 5);

    ::testing::internal::CaptureStdout();
    sort_5_numbers(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    // It must push two elements to B
    int count_pb = 0, pos = 0;
    while ((pos = out.find("pb\n", pos)) != std::string::npos) { count_pb++; pos += 3; }
    EXPECT_EQ(count_pb, 2);

    // And later bring them back with pa (at least twice)
    EXPECT_NE(out.find("pa\n"), std::string::npos);

    // Final state: A sorted, B empty, sizes preserved
    EXPECT_EQ(a.size, 5);
    EXPECT_EQ(b.size, 0);
    EXPECT_TRUE(stack_is_sorted(&a));

    free_stack(a);
    free_stack(b);
}

// ---------- sort_rest_numbers (radix path) ----------

TEST(SortOperationsTest, SortRestNumbers_IndexesThenSortsAscending_BEmpty) {
    // More than 5 elements -> radix path
    // Note: sort_rest_numbers calls index_stack_temp, so values turn into 0..n-1 then do_sort sorts them.
    t_stack a = make_stack({42, 5, 7, 99, 13, 0, 21}, 7);
    t_stack b = make_stack({}, 7);

    ::testing::internal::CaptureStdout();
    sort_rest_numbers(&a, &b);
    std::string out = ::testing::internal::GetCapturedStdout();

    // After indexing + sort, expect 0..n-1 in ascending order
    ASSERT_EQ(a.size, 7);
    EXPECT_TRUE(stack_is_sorted(&a));
    for (int i = 0; i < a.size; ++i) {
        EXPECT_EQ(a.array[i], i);
    }

    EXPECT_EQ(b.size, 0);
    // Some combination of pb/ra/pa should have been printed
    EXPECT_FALSE(out.empty());

    free_stack(a);
    free_stack(b);
}
