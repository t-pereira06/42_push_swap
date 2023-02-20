/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:45:38 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/20 11:39:11 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*operation 1*/
void	op_1(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
}

/*operation 2*/
void	op_2(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
	sa(stack_a);
}

/*call functions to organize stack_a if sort_5_numbers is called*/
void	operations(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	*a;
	int	*b;

	i = 0;
	a = stack_a->array;
	b = stack_b->array;
	while (i <= 1)
	{
		if (b[0] < a[0])
			op_1(stack_a, stack_b);
		else if (b[0] > a[0] && b[0] < a[1])
			op_2(stack_a, stack_b);
		else if (i == 0 && b[0] > a[0] && b[0] > a[1] && b[0] < a[2])
			op_3(stack_a, stack_b);
		else if (i == 1 && b[0] > a[0] && b[0] > a[1] && b[0] < a[2])
			op_4(stack_a, stack_b);
		else if (b[0] > a[0] && b[0] > a[1] && b[0] > a[2] && b[0] < a[3])
			op_5(stack_a, stack_b);
		else if (b[0] > a[2])
			op_6(stack_a, stack_b);
		i++;
	}
}
