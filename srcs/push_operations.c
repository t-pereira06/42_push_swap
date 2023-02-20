/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:52:12 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/20 11:35:50 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*fill_stack_a after doing pb*/
void	fill_stack_a(t_stack *stack_a)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * (stack_a->size));
	while (i < stack_a->size)
	{
		tmp[i] = stack_a->array[i];
		i++;
	}
	free(stack_a->array);
	stack_a->array = (int *)malloc(sizeof(int) * (stack_a->size - 1));
	stack_a->size -= 1;
	i = 1;
	while (i <= stack_a->size)
	{
		stack_a->array[i - 1] = tmp[i];
		i++;
	}
	free(tmp);
}

/*fill_stack_a after doing pa*/
void	fill_stack_b(t_stack *stack_b)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * (stack_b->size));
	while (i < stack_b->size)
	{
		tmp[i] = stack_b->array[i];
		i++;
	}
	free(stack_b->array);
	stack_b->array = (int *)malloc(sizeof(int) * (stack_b->size - 1));
	stack_b->size -= 1;
	i = 1;
	while (i <= stack_b->size)
	{
		stack_b->array[i - 1] = tmp[i];
		i++;
	}
	free(tmp);
}

/*Send top of B to top of A*/
int	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * (stack_a->size));
	if (stack_b->size == 0)
		return (0);
	while (i < stack_a->size)
	{
		tmp[i] = stack_a->array[i];
		i++;
	}
	free(stack_a->array);
	stack_a->array = (int *)malloc(sizeof(int) * (stack_a->size + 1));
	stack_a->array[0] = stack_b->array[0];
	stack_a->size += 1;
	i = 1;
	while (i < stack_a->size)
	{
		stack_a->array[i] = tmp[i - 1];
		i++;
	}
	fill_stack_b(stack_b);
	free(tmp);
	return (ft_printf("%s", "pa\n"));
}

/*Send top of A to top of B*/
int	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * (stack_b->size));
	if (stack_a->size == 0)
		return (0);
	while (i < stack_b->size)
	{
		tmp[i] = stack_b->array[i];
		i++;
	}
	free(stack_b->array);
	stack_b->array = (int *)malloc(sizeof(int) * (stack_b->size + 1));
	stack_b->array[0] = stack_a->array[0];
	stack_b->size += 1;
	i = 1;
	while (i < stack_b->size)
	{
		stack_b->array[i] = tmp[i - 1];
		i++;
	}
	fill_stack_a(stack_a);
	free(tmp);
	return (ft_printf("%s", "pb\n"));
}
