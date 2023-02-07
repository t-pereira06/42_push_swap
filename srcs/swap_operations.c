/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:52:15 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/07 11:43:01 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*swap the first element with the second in stack a*/
void	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size > 1)
	{
		tmp = stack_a->array[0];
		stack_a->array[0] = stack_a->array[1];
		stack_a->array[1] = tmp;
	}
	ft_printf("%s", "sa\n");
}

/*swap the first element with the second in stack b*/
void	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size > 1)
	{
		tmp = stack_b->array[0];
		stack_b->array[0] = stack_b->array[1];
		stack_b->array[1] = tmp;
	}
	ft_printf("%s", "sb\n");
}

/*run both sa and sb at the same time*/
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

