/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:52:40 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/20 14:52:49 by tsodre-p         ###   ########.fr       */
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
	ft_printf("%s", "rra\n");
}

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
	ft_printf("%s", "rrb\n");
}

/*execute both rra and rrb at the
same time*/
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
