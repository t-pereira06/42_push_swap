/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:46:10 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/06 11:50:21 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*rotate all elements by 1 in stack_b,
last element becomes the first one*/
void	rrb(t_stack *stack_b)
{
	int	*tmp;
	int	i;

	i = 0;
	if (stack_b->size > 1)
	{
		tmp = (int *)malloc(sizeof(int) * (stack_b->size));
		while (i < stack_b->size)
		{
			tmp[i] = stack_b->array[i];
			i++;
		}
		free(stack_b->array);
		stack_b->array = (int *)malloc(sizeof(int) * (stack_b->size));
		stack_b->array[0] = tmp[stack_b->size - 1];
		i = 1;
		while (i < stack_b->size)
		{
			stack_b->array[i] = tmp[i - 1];
			i++;
		}
		free(tmp);
	}
}
