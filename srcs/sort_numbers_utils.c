/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:45:38 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/15 11:03:34 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	op_1(t_stack *stack_a, t_stack *stack_b)
{
	int	operations;

	operations = 0;
	pa(stack_a, stack_b);
	operations = 1;
	return (operations);
}

int	op_2(t_stack *stack_a, t_stack *stack_b)
{
	int	operations;

	operations = 0;
	pa(stack_a, stack_b);
	sa(stack_a);
	operations = 2;
	return (operations);
}

int	operations(t_stack *stack_a, t_stack *stack_b)
{
	int	operations;
	int	i;
	int	*a;
	int	*b;

	i = 0;
	a = stack_a->array;
	b = stack_b->array;
	operations = 0;
	while (i < 2)
	{
		if (b[0] < a[0])
			operations += op_1(stack_a, stack_b);
		else if(b[0] > a[0] && b[0] < a[1])
			operations += op_2(stack_a, stack_b);
		else if (i == 0 && b[0] > a[0] && b[0] > a[1] && b[0] < a[2])
			operations += op_3(stack_a, stack_b);
		else if (i == 1 && b[0] > a[0] && b[0] > a[1] && b[0] < a[2])
			operations += op_4(stack_a, stack_b);
		else if (b[0] > a[0] && b[0] > a[1] && b[0] > a[2] && b[0] < a[3])
			operations += op_4(stack_a, stack_b);
		else if (b[0] > a[2])
			operations += op_6(stack_a, stack_b);
		i++;
	}
	return (operations);
}
