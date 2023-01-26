/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:04:51 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/26 14:42:08 by tsodre-p         ###   ########.fr       */
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
}
