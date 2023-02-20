/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:56:11 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/20 11:39:30 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*operation 3*/
void	op_3(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
}

/*operation 4*/
void	op_4(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
	ra(stack_a);
}

/*operation 5*/
void	op_5(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
}

/*operation 6*/
void	op_6(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
	ra(stack_a);
}
