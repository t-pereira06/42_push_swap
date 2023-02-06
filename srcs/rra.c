/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:19:08 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/06 11:46:24 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*rotate all elements by 1 in stack_a,
last element becomes the first one*/
void	rra(t_stack *stack_a)
{
	int	*tmp;
	int	i;

	i = 0;
	if (stack_a->size > 1)
	{
		tmp = (int *)malloc(sizeof(int) * (stack_a->size));
		while (i < stack_a->size)
		{
			tmp[i] = stack_a->array[i];
			i++;
		}
		free(stack_a->array);
		stack_a->array = (int *)malloc(sizeof(int) * (stack_a->size));
		stack_a->array[0] = tmp[stack_a->size - 1];
		i = 1;
		while (i < stack_a->size)
		{
			stack_a->array[i] = tmp[i - 1];
			i++;
		}
		free(tmp);
	}
}
