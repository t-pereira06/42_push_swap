#include <gtest/gtest.h>

// --- Handle libft.h keyword clash ---
extern "C" {
	#define new dont_use_new          // temporary rename to avoid C++ keyword conflict
	#include "../libft/libft.h"
	#undef new                        // restore "new" keyword
	#include "../includes/push_swap.h"
	//#include "test_indexing.h"        // prototypes for the functions under test
	#include <stdlib.h>
}

// Helper: create stack easily
static t_stack make_stack(std::initializer_list<int> values) {
	t_stack stack;
	stack.size = values.size();
	stack.array = (int*)malloc(stack.size * sizeof(int));
	int i = 0;
	for (int v : values) {
		stack.array[i++] = v;
	}
	return stack;
}

// Helper: free stack memory
static void free_stack(t_stack& stack) {
	free(stack.array);
	stack.array = nullptr;
	stack.size = 0;
}

// ---------------- TESTS ---------------- //

TEST(IndexingTest, ReturnsLargestElement) {
	t_stack s = make_stack({3, 7, 2, 10, 5});
	EXPECT_EQ(get_max_value(&s), 10);
	free_stack(s);
}

TEST(IndexingTest, ConvertsValuesToSortedIndices) {
	t_stack s = make_stack({40, 10, 30});
	int sorted_temp[] = {10, 30, 40}; // expected sorted version

	convert_to_index(&s, sorted_temp);

	// after conversion, s.array should hold indices [2,0,1]
	EXPECT_EQ(s.array[0], 2);
	EXPECT_EQ(s.array[1], 0);
	EXPECT_EQ(s.array[2], 1);

	free_stack(s);
}

TEST(IndexingTest, SortsAndIndexesAutomatically) {
	t_stack s = make_stack({50, 20, 30});

	index_stack_temp(&s);

	// Sorted temp = {20,30,50}, so mapping is:
	// 50 -> 2, 20 -> 0, 30 -> 1
	EXPECT_EQ(s.array[0], 2);
	EXPECT_EQ(s.array[1], 0);
	EXPECT_EQ(s.array[2], 1);

	free_stack(s);
}

TEST(IndexingTest, DetectsSortedArray) {
	t_stack sorted = make_stack({1, 2, 3, 4});
	t_stack unsorted = make_stack({4, 2, 1});

	EXPECT_TRUE(stack_is_sorted(&sorted));
	EXPECT_FALSE(stack_is_sorted(&unsorted));

	free_stack(sorted);
	free_stack(unsorted);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
