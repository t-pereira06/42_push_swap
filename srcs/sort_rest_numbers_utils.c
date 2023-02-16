/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest_numbers_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:30:38 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/16 15:19:47 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	verify_next_index(t_stack *stack_a, int i)
{
	int	j;
	int	mid_stack;
	int	res;

	j = 0;
	res = 0;
	mid_stack = get_mid_stack(stack_a);
	i = 0;
	//ver qual o numero mais proximo que tenha 0 naquele bit
	while(j < stack_a->size)
	{
		if(((stack_a->array[j] >> i) & 1) == 0)
		{
			res = j;
			if (j <= mid_stack)
			{
				while(res > 0)
				{
					ra(stack_a);
					res--;
				}
			}
			else if (j > mid_stack)
			{
				while(res > 0)
				{
					rra(stack_a);
					res--;
				}
			}
			break;
		}
		else
			j++;
	}
}
