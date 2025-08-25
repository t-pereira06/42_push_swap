/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:48:18 by tsodre-p          #+#    #+#             */
/*   Updated: 2025/08/25 11:50:13 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct stack
{
	int			*array;
	int			size;
}					t_stack;

// void	sa(t_stack *stack_a);
// void	sb(t_stack *stack_b);
// void	ss(t_stack *stack_a, t_stack *stack_b);
// int		pa(t_stack *stack_a, t_stack *stack_b);
// int		pb(t_stack *stack_a, t_stack *stack_b);
// void	ra(t_stack *stack_a);
// void	rb(t_stack *stack_b);
// void	rr(t_stack *stack_a, t_stack *stack_b);
// void	rra(t_stack *stack_a);
// void	rrb(t_stack *stack_b);
// void	rrr(t_stack *stack_a, t_stack *stack_b);
// void	initialize_stacks(t_stack *stack_a, t_stack *stack_b);
// int		check_stack(char *argv, t_stack *stack_a, t_stack *stack_b);
// int		fill_stack(char *argv, t_stack *stack_a, t_stack *stack_b);
// int		fill_stack_split(char *argv, t_stack *stack_a, t_stack *stack_b);
// void	sort_2_numbers(t_stack *stack_a);
// void	sort_3_numbers(t_stack *stack_a);
// void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b);
// void	sort_rest_numbers(t_stack *stack_a, t_stack *stack_b);
// void	operations(t_stack *stack_a, t_stack *stack_b);
// void	op_3(t_stack *stack_a, t_stack *stack_b);
// void	op_4(t_stack *stack_a, t_stack *stack_b);
// void	op_5(t_stack *stack_a, t_stack *stack_b);
// void	op_6(t_stack *stack_a, t_stack *stack_b);
// void	index_stack_temp(t_stack *stack_a);
// int		get_max_value(t_stack *stack_a);
// int		stack_is_sorted(t_stack *stack_a);
// void	do_sort(t_stack *stack_a, t_stack *stack_b, int max_bits);

//indexing.c
int		get_max_value(t_stack *stack_a);
void	convert_to_index(t_stack *stack_a, int *temp);
void	index_stack_temp(t_stack *stack_a);
int		stack_is_sorted(t_stack *stack_a);

//push_operations.c
void	fill_stack_a(t_stack *stack_a);
void	fill_stack_b(t_stack *stack_b);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);

//rev_rotate_operations.c
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//rotate_operations.c
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

//sort_numbers_utils.c
void	op_1(t_stack *stack_a, t_stack *stack_b);
void	op_2(t_stack *stack_a, t_stack *stack_b);
void	operations(t_stack *stack_a, t_stack *stack_b);

//sort_operations_utils_2.c
void	pass_numbers_to_a(t_stack *stack_a, t_stack *stack_b, int size_b);
void	check_bit(t_stack *stack_a, t_stack *stack_b, int i);
void	do_sort(t_stack *stack_a, t_stack *stack_b, int max_bits);

//sort_operations_utils.c
void	op_3(t_stack *stack_a, t_stack *stack_b);
void	op_4(t_stack *stack_a, t_stack *stack_b);
void	op_5(t_stack *stack_a, t_stack *stack_b);
void	op_6(t_stack *stack_a, t_stack *stack_b);

//sort_operations.c
void	sort_2_numbers(t_stack *stack_a);
void	sort_3_numbers(t_stack *stack_a);
void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b);
void	sort_rest_numbers(t_stack *stack_a, t_stack *stack_b);

//start_stacks.c
void	initialize_stacks(t_stack *stack_a, t_stack *stack_b);
int		check_stack(char *argv, t_stack *stack_a, t_stack *stack_b);
int		fill_stack(char *argv, t_stack *stack_a, t_stack *stack_b);
void	free_split(char **stack, int i);
int		fill_stack_split(char *argv, t_stack *stack_a, t_stack *stack_b);

//swap_operations.c
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

#endif
