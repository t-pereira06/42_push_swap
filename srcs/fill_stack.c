/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:06:32 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/20 14:09:26 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*functions to fill the stacks, counting the size of it and fill it in the struct field size*/
#include "../includes/push_swap.h"

int	size_arg(char *arg)
{
	int	i;

	while (arg[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	count_stack_size(int argc, char *argv[])
{
	int	i;
	int	j;
	int	size;

	size = 0;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			size++;
			j++;
		}
		i++;
	}
	return (size);
}

int	fill_stack(int argc, char *argv, t_stack *stack_a)
{
	int	i;
	int	a;

	i = stack_a->size;
	a = 0;
	while (i < argc)
	{
		stack_a->size += size_arg(argv[1]);
		while (argv[i] != '\0')
		{
			stack_a->array[i] = ft_atoi(argv[i]);
			a++;
		}
		i++;
	}
}

int	init_stacks(int argc, char *argv, t_stack *stack_a, t_stack *stack_b)
{
	int	stack_size;

	stack_size = count_stack_size(argc, argv);
	if (!(stack_a->array = malloc(sizeof(int) * stack_size)))
	{
		ft_printf("%s", "Error allocating stack_a!\n");
		return (0);
	}
	if (!(stack_b->array = malloc(sizeof(int) * stack_size)))
	{
		free(stack_a->array);
		ft_printf("%s", "Error allocating stack_b!");
		return (0);
	}
	stack_a->max_size = stack_size;
	stack_b->max_size = stack_size;
	stack_a->size = 0;
	stack_b->size = 0;
	if (!fill_stack(argc, argv, stack_a))
	{
		free(stack_a->array);
		free(stack_b->array);
		ft_printf("%s", "Error filling the stack!");
		return (0);
	}
	return (0);
}
