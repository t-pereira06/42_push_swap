#include <gtest/gtest.h>

extern "C" {
	#define new dont_use_new
	#include "../libft/libft.h"
	#undef new
	#include "../includes/push_swap.h"
	#include "test_push_operations.h"  // or a dedicated header for prototypes
	#include <stdlib.h>
}

// ---------------- Helpers ---------------- //
static t_stack make_stack(std::initializer_list<int> values, int capacity = -1) {
	t_stack stack;
	stack.size = values.size();
	int cap = (capacity == -1) ? stack.size : capacity;
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

TEST(PushOperationsTest, FillStackARemovesTopElementAndShifts) {
	t_stack a = make_stack({10, 20, 30}, 3);
	fill_stack_a(&a);
	EXPECT_EQ(a.size, 2);
	EXPECT_EQ(a.array[0], 20);
	EXPECT_EQ(a.array[1], 30);
	free_stack(a);
}

TEST(PushOperationsTest, FillStackBRemovesTopElementAndShifts) {
	t_stack b = make_stack({5, 15, 25}, 3);
	fill_stack_b(&b);
	EXPECT_EQ(b.size, 2);
	EXPECT_EQ(b.array[0], 15);
	EXPECT_EQ(b.array[1], 25);
	free_stack(b);
}

TEST(PushOperationsTest, PaMovesTopOfBToTopOfA) {
	t_stack a = make_stack({100, 200}, 3);
	t_stack b = make_stack({50, 60}, 3);

	int ret = pa(&a, &b);

	EXPECT_NE(ret, 0);           // ft_printf return, just check non-zero
	EXPECT_EQ(a.size, 3);
	EXPECT_EQ(a.array[0], 50);
	EXPECT_EQ(a.array[1], 100);
	EXPECT_EQ(a.array[2], 200);

	EXPECT_EQ(b.size, 1);
	EXPECT_EQ(b.array[0], 60);

	free_stack(a);
	free_stack(b);
}

TEST(PushOperationsTest, PbMovesTopOfAToTopOfB) {
	t_stack a = make_stack({10, 20}, 3);
	t_stack b = make_stack({30}, 3);

	int ret = pb(&a, &b);

	EXPECT_NE(ret, 0);
	EXPECT_EQ(a.size, 1);
	EXPECT_EQ(a.array[0], 20);

	EXPECT_EQ(b.size, 2);
	EXPECT_EQ(b.array[0], 10);
	EXPECT_EQ(b.array[1], 30);

	free_stack(a);
	free_stack(b);
}

TEST(PushOperationsTest, PaHandlesEmptyBGracefully) {
	t_stack a = make_stack({1, 2}, 3);
	t_stack b = make_stack({}, 3);

	int ret = pa(&a, &b);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(a.size, 2);
	EXPECT_EQ(b.size, 0);

	free_stack(a);
	free_stack(b);
}

TEST(PushOperationsTest, PbHandlesEmptyAGracefully) {
	t_stack a = make_stack({}, 3);
	t_stack b = make_stack({5}, 3);

	int ret = pb(&a, &b);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(a.size, 0);
	EXPECT_EQ(b.size, 1);

	free_stack(a);
	free_stack(b);
}
