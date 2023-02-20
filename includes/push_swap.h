/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:48:18 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/20 11:27:43 by tsodre-p         ###   ########.fr       */
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

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	initialize_stacks(t_stack *stack_a, t_stack *stack_b);
int		check_stack(char *argv, t_stack *stack_a, t_stack *stack_b);
int		fill_stack(char *argv, t_stack *stack_a, t_stack *stack_b);
int		fill_stack_split(char *argv, t_stack *stack_a, t_stack *stack_b);
void	sort_2_numbers(t_stack *stack_a);
void	sort_3_numbers(t_stack *stack_a);
void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b);
void	sort_rest_numbers(t_stack *stack_a, t_stack *stack_b);
void	operations(t_stack *stack_a, t_stack *stack_b);
void	op_3(t_stack *stack_a, t_stack *stack_b);
void	op_4(t_stack *stack_a, t_stack *stack_b);
void	op_5(t_stack *stack_a, t_stack *stack_b);
void	op_6(t_stack *stack_a, t_stack *stack_b);
void	index_stack_temp(t_stack *stack_a);
int		get_max_value(t_stack *stack_a);
int		stack_is_sorted(t_stack *stack_a);
void	do_sort(t_stack *stack_a, t_stack *stack_b, int max_bits);

#endif
