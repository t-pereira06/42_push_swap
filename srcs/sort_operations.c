/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/07 17:32:18 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*order 3 random numbers*/
int	sort_3_numbers(t_stack *stack_a)
{
	int	*a;
	int	operations;

	operations = 1;
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
		operations = 2;
	}
	else if ((a[1] > a[0]) && (a[1] > a[2]) && a[0] < a[2])
	{
		sa(stack_a);
		ra(stack_a);
		operations = 2;
	}
	return (operations);
}

int	find_lowest_number(t_stack *stack_a)
{
	int	pos;
	int	i;

	pos = 100;
	i = 0;
	while (pos < stack_a->size)
	{
		while (i < stack_a->size)
		{
			if (pos == stack_a->array[i])
			{
				pos = i;
				break;
			}
			i++;
		}
		pos--;
	}
	return (pos);
}
