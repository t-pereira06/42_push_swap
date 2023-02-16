/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/16 16:33:41 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*order 2 random numbers*/
void	sort_2_numbers(t_stack *stack_a)
{
	if (stack_a->array[1] < stack_a->array[0])
		sa(stack_a);
}

/*order 3 random numbers*/
void	sort_3_numbers(t_stack *stack_a)
{
	int	*a;

	a = stack_a->array;
	if ((a[0] > a[1]) && (a[0] < a[2]))
		sa(stack_a);
	else if ((a[0] > a[1]) && (a[0] > a[2]) && (a[1] < a[2]))
		ra(stack_a);
	else if ((a[2] < a[1]) && (a[1] > a[0]) && (a[0] > a[2]))
		rra(stack_a);
	else if ((a[0] > a[1]) && (a[1] > a[2]))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((a[1] > a[0]) && (a[1] > a[2]) && a[0] < a[2])
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3_numbers(stack_a);
	sort_2_numbers(stack_b);
	operations(stack_a, stack_b);
}

void	sort_rest_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	max_bits;
	int	max_number;
	int	size_a;
	int	size_b;

	j = 0;
	i = 0;
	max_bits = 0;
	index_stack_temp(stack_a);
	max_number = get_max_value(stack_a);
	while((max_number >> max_bits) != 0)
		max_bits++;
	while(i <= max_bits)
	{
		size_a = stack_a->size;
		j = 0;
		while(j < size_a)
		{
			if(((stack_a->array[0] >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
			{
				//verify_next_index(stack_a, i);
				//pb(stack_a, stack_b);
				ra(stack_a);
			}
			j++;
		}
		size_b = stack_b->size;
		while(size_b > 0)
		{
			if (((stack_a->array[0] >> (i - 1)) & 1) == 0)
				rrb(stack_b);
			else
			{
				pa(stack_a, stack_b);
				size_b--;
			}
		}
		if(stack_is_sorted(stack_a) == 1)
			break;
		i++;
	}
}
