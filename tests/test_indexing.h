#ifndef INDEXING_TEST_H
#define INDEXING_TEST_H

#include "../includes/push_swap.h"

int     get_max_value(t_stack *stack_a);
void    convert_to_index(t_stack *stack_a, int *temp);
void    index_stack_temp(t_stack *stack_a);
int     stack_is_sorted(t_stack *stack_a);

#endif
