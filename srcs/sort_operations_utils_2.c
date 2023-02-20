/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:54:09 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/20 11:31:11 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*pass numbers to stack_b*/
void	pass_numbers_to_a(t_stack *stack_a, t_stack *stack_b, int size_b)
{
	while (size_b > 0)
	{
		pa(stack_a, stack_b);
		size_b--;
	}
}

/*check if the number has 0 on that bit comparison*/
void	check_bit(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (((stack_a->array[0] >> i) & 1) == 0)
		pb(stack_a, stack_b);
	else
		ra(stack_a);
}

/*order numbers*/
void	do_sort(t_stack *stack_a, t_stack *stack_b, int max_bits)
{
	int	i;
	int	j;
	int	size_a;
	int	size_b;

	size_a = 0;
	size_b = 0;
	j = 0;
	i = 0;
	while (i <= max_bits)
	{
		size_a = stack_a->size;
		j = 0;
		while (j < size_a)
		{
			check_bit(stack_a, stack_b, i);
			j++;
		}
		size_b = stack_b->size;
		pass_numbers_to_a(stack_a, stack_b, size_b);
		if (stack_is_sorted(stack_a) == 1)
			break ;
		i++;
	}
}
