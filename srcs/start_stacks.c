/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:06:32 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/15 11:28:14 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*functions to fill the stacks, allocate memory for the array,
counting the size of it and fill it in the struct field size*/
#include "../includes/push_swap.h"

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->array = 0;
	stack_b->size = 0;
	stack_b->array = 0;
}

int	check_stack(char *argv, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (ft_atoi(argv) == stack_a->array[i])
		{
			write(1, "Error!\n", 8);
			free(stack_a->array);
			free(stack_b->array);
			exit (1);
		}
		i++;
	}
	return (1);
}

int	fill_stack(char *argv, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (argv[0] == '-')
	{
		i++;
	}
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]) || (ft_atol(argv) > INT32_MAX))
		{
			write(1, "Error!\n", 8);
			exit (1);
		}
		i++;
	}
	stack_a->size += 1;
	if (check_stack(argv, stack_a, stack_b) == 1)
	{
		stack_a->array[stack_a->size - 1] = ft_atoi(argv);
	}
	else
		stack_a->size -= 1;
	return (stack_a->size);
}

int	fill_stack_split(char *argv, t_stack *stack_a, t_stack *stack_b)
{
	char	**split;
	int		i;
	int		stack_size;

	i = 0;
	stack_size = 0;
	split = ft_split(&argv[i], ' ');
	while (split[i])
	{
		stack_size = fill_stack(split[i], stack_a, stack_b);
		i++;
	}
	return (stack_size);
}
