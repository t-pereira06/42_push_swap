/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:52:24 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/20 11:56:35 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*rotate all elements by 1 in stack_a,
last element becomes the first one*/
void	ra(t_stack *stack_a)
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
		i = 0;
		while (i < stack_a->size - 1)
		{
			stack_a->array[i] = tmp[i + 1];
			i++;
		}
		stack_a->array[stack_a->size - 1] = tmp[0];
		free(tmp);
	}
	ft_printf("%s", "ra\n");
}

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
	ft_printf("%s", "rb\n");
}

/*execute both ra and rb at the
same time*/
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
