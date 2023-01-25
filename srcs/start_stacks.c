/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:06:32 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/25 16:08:32 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*functions to fill the stacks, counting the size of it and fill it in the struct field size*/
#include "../includes/push_swap.h"
void	initialize_stacks(stack stack_a, stack stack_b)
{
	stack_a.size = 0;
	stack_a.array = 0;
	stack_b.size = 0;
	stack_b.array = 0;
}

void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc < 2)
	{
		write(1, "Please introduce a valid number of arguments!\n", 47);
		exit (1);
	}
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(1, "Not all the arguments are numbers!\n", 36);
				exit (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	fill_stack(char *argv, stack stack_a, int a)
{
	stack_a.size += 1;
	stack_a.array[a] = ft_atoi(argv);
	return (stack_a.size);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	stack	stack_a;
	stack	stack_b;

	i = 1;
	j = 0;
	initialize_stacks(stack_a, stack_b);
	stack_a.size = 0;
	stack_a.array = (int *)malloc(sizeof(int) * (argc - 1));
	stack_b.size = 0;
	stack_b.array = (int *)malloc(sizeof(int) * (argc - 1));
	//check_args(argc, argv);
	while (argv[i])
	{
		stack_a.size = fill_stack(argv[i], stack_a, j);
		i++;
		j++;
	}
	j = 0;
	printf("%s", "Array size: ");
	printf("%d", stack_a.size);
	printf("%s", "\n");
	printf("%s", "Array: ");
	while (j < stack_a.size)
	{
		printf("%d", stack_a.array[j]);
		printf("%s", " | ");
		j++;
	}
	return (0);
}
