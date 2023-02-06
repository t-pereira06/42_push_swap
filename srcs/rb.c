/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:47:12 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/06 13:02:27 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*rotate all elements by 1 in stack_a,
first element becomes the last one*/
void	rb(t_stack *stack_b)
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
		i = 0;
		while (i < stack_b->size - 1)
		{
			stack_b->array[i] = tmp[i + 1];
			i++;
		}
		stack_b->array[stack_b->size - 1] = tmp[0];
		free(tmp);
	}
}
