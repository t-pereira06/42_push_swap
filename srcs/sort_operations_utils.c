/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:56:11 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/15 11:04:56 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	op_3(t_stack *stack_a, t_stack *stack_b)
{
	int	operations;

	operations = 0;
	rra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
	operations = 4;
	return (operations);
}

int	op_4(t_stack *stack_a, t_stack *stack_b)
{
	int	operations;

	operations = 0;
	rra(stack_a);
	rra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
	ra(stack_a);
	operations = 6;
	return (operations);
}

int	op_5(t_stack *stack_a, t_stack *stack_b)
{
	int	operations;

	operations = 0;
	pa(stack_a, stack_b);
	ra(stack_a);
	operations = 2;
	return (operations);
}

int	op_6(t_stack *stack_a, t_stack *stack_b)
{
	int	operations;

	operations = 0;
	pa(stack_a, stack_b);
	ra(stack_a);
	operations = 2;
	return (operations);
}
