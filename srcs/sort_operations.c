/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/07 12:00:05 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*order 3 random numbers*/
int	sort_3_num(t_stack *stack_a)
{
	int	*a;
	int	operations;

	operations = 1;
	a = stack_a->array;
	/*case 1*/
	if ((a[0] > a[1]) && (a[0] < a[2]))
		sa(stack_a);
	/*case 3*/
	else if ((a[0] > a[1]) && (a[0] > a[2]) && (a[1] < a[2]))
		ra(stack_a);
	/*case 5*/
	else if ((a[2] < a[1]) && (a[1] > a[0]) && (a[0] > a[2]))
		rra(stack_a);
	/*case 2*/
	else if ((a[0] > a[1]) && (a[1] > a[2]))
	{
		sa(stack_a);
		rra(stack_a);
		operations = 2;
	}
	/*case 4*/
	else if ((a[1] > a[0]) && (a[1] > a[2]) && a[0] < a[2])
	{
		sa(stack_a);
		ra(stack_a);
		operations = 2;
	}
	return (operations);
}
