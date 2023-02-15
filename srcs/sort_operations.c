/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/15 15:18:57 by tsodre-p         ###   ########.fr       */
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

/*order as many numbers as you want*/
void	best_move(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	res;
	int	num;

	res = 0;
	num = stack_a->array[index];
	res = stack_a->size / 2;
	if (index > res)
	{
		while (stack_a->array[0] != num)
		{
			rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	else if (index <= res)
	{
		while (stack_a->array[0] != num)
		{
			ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

void	sort_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	best_move(stack_a, stack_b, index);
	while (stack_a->size != 0)
	{
		while (i < stack_a->size)
		{
			if (stack_a->array[i] < stack_a->array[i + 1])
			{
				index = i + 1;
			}
			i++;
		}
		best_move(stack_a, stack_b, index);
		stack_a->size -= 1;
	}
	while (stack_b->size != 0)
	{
		pa(stack_a, stack_b);
		stack_a->size++;
		stack_b->size--;
	}
}
//https://github.com/AdrianWR/push_swap ver logica explicada
