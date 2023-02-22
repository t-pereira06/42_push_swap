/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:06:32 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/22 15:03:41 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*functions to fill the stacks, allocate memory for the array,
counting the size of it and fill it in the struct field size*/
#include "../includes/push_swap.h"

/*initialize stacks with 0*/
void	initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->array = 0;
	stack_b->size = 0;
	stack_b->array = 0;
}

/*check if number already exists in stack_a*/
int	check_stack(char *argv, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (ft_atoi(argv) == stack_a->array[i])
		{
			write(2, "Error\n", 6);
			write(2, "check_stack", 12);
			free(stack_a->array);
			free(stack_b->array);
			exit (1);
		}
		i++;
	}
	return (1);
}

/*fill stack with arguments passed*/
int	fill_stack(char *argv, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (argv[0] == '-')
		i++;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]) || (ft_atol(argv) > INT32_MAX)
			|| (ft_atol(argv) < INT32_MIN))
		{
			write(2, "Error\n", 6);
			free(stack_a->array);
			free(stack_b->array);
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

/*free the **split used to pass the
arguments to stack*/
void	free_split(char **stack, int i)
{
	int	j;

	j = 0;
	while (i > 0)
	{
		free(stack[j]);
		i--;
		j++;
	}
	free(stack);
}

/*fill stack with arguments passed if there is only 1
string with numbers, using ft_split to get the args*/
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
	free_split(split, i);
	return (stack_size);
}
