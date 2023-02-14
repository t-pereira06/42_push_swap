/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/14 09:42:23 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*order 2 random numbers*/
int	sort_2_numbers(t_stack *stack_a)
{
	int	operations;

	operations = 0;
	if (stack_a->array[1] < stack_a->array[0])
	{
		sa(stack_a);
		operations++;
	}
	return (operations);
}

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

int	sort_5_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	operations;
	int	i;
	int	*a;
	int	*b;

	operations = 0;
	i = 0;
	a = stack_a->array;
	b = stack_b->array;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	operations += 2;
	operations += sort_3_numbers(stack_a);
	operations += sort_2_numbers(stack_b);
	while (i < 2)
	{
		if (b[0] < a[0])
		{
			pa(stack_a, stack_b);
			operations++;
		}
		else if(b[0] > a[0] && b[0] < a[1])
		{
			pa(stack_a, stack_b);
			sa(stack_a);
			operations += 2;
		}
		else if (b[0] > a[0] && b[0] > a[1] && b[0] < a[2])
		{
			rra(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
			ra(stack_a);
			operations += 4;
		}
		else if (b[0] > a[0] && b[0] > a[1] && b[0] < a[2] && b[0] < a[3])
		{
			rra(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
			ra(stack_a);
			operations += 4;
		}
		else if (b[0] > a[2])
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			operations += 2;
		}
		i++;
	}
	return (operations);
}

/*int	find_lowest_number(t_stack *stack_a)
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
}*/

/*order as many numbers as you want*/
void	best_move(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	res;

	res = 0;
	res = stack_a->size / 2;
	if (stack_a->array[i] > res)
	{
		while (!(stack_a->array[0] == stack_a->array[i]))
		{
			rra(stack_a);
		}
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else if (stack_a->array[i] <= res)
	{
		while (stack_a->array[0] != stack_a->array[i])
		{
			ra(stack_a);
		}
		pb(stack_a, stack_b);
		rb(stack_b);
	}
}

int	sort_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	num;
	int	operations;

	i = 0;
	num = 1;
	operations = 0;
	while (num != stack_a->size)
	{
		while (stack_a->array[i] != num)
		{
			i++;
		}
		best_move(stack_a, stack_b, i);
		i = 0;
		num++;
	}
	while (stack_b->size != 0)
	{
		pa(stack_a, stack_b);
		rra(stack_b);
		operations += 2;
		stack_b->size--;
	}
	return (operations);
}

//https://github.com/AdrianWR/push_swap ver logica explicada
