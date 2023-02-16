/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:54:39 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/16 12:04:05 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_value(t_stack *stack_a)
{
	int	i;
	int	temp;

	i = 0;
	while(i < stack_a->size - 1)
	{
		if (stack_a->array[i] < stack_a->array[i + 1])
		{
			temp = stack_a->array[i + 1];
		}
		i++;
	}
	return (temp);
}

void	convert_to_index(t_stack *stack_a, int *temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a->size)
	{
		j = 0;
		while (j < stack_a->size)
		{
			if (stack_a->array[i] == temp[j])
			{
				stack_a->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	index_stack_temp(t_stack *stack_a)
{
	int	*temp;
	int	temp_num;
	int	i;

	i = 0;
	temp = ft_calloc(sizeof(int), stack_a->size);
	temp = ft_memcpy(temp, stack_a->array, sizeof(int) * stack_a->size);
	while(i < stack_a->size - 1)
	{
		if(temp[i] > temp[i + 1])
		{
			temp_num = temp[i];
			temp[i] = temp[i + 1];
			temp[i + 1] = temp_num;
			i = 0;
		}
		else
			i++;
	}
	convert_to_index(stack_a, temp);
	free(temp);
}

int	stack_is_sorted(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < (stack_a->size - 1))
	{
		if (stack_a->array[i] > stack_a->array[i + 1])
			return(0);
		i++;
	}
	return (1);
}

int	get_mid_stack(t_stack *stack_a)
{
	int	a;

	a = stack_a->size / 2;
	return (a);
}
