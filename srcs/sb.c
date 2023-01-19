/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:29:36 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/19 14:57:00 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void	sb(t_stack *stack_b)
{
	int tmp;

	if (stack_b->size > 1)
	{
		tmp = stack_b->array[0];
		stack_b->array[0] = stack_b->array[1];
		stack_b->array[1] = tmp;
	}
}