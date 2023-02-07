/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:06:32 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/07 15:35:33 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*functions to fill the stacks, allocate memory for the array,
counting the size of it and fill it in the struct field size*/
#include "../includes/push_swap.h"

void	print_stacks(t_stack stack_a, t_stack stack_b)
{
	int	j;

	j = 0;
	printf("%s", "Array A size: ");
	printf("%d", stack_a.size);
	printf("%s", "\n");
	printf("%s", "Array A: ");
	while (j < stack_a.size)
	{
		if(stack_a.array[0] == 0)
		{
			printf("%s", "(null)");
			break;
		}
		printf("%d", stack_a.array[j]);
		printf("%s", "|");
		j++;
	}
	printf("%s", "\n");
	j = 0;
	printf("%s", "Array B size: ");
	printf("%d", stack_b.size);
	printf("%s", "\n");
	printf("%s", "Array B: ");
	while (j < stack_b.size)
	{
		if(stack_b.array[0] == 0)
		{
			printf("%s", "(null)");
			break;
		}
		printf("%d", stack_b.array[j]);
		printf("%s", "|");
		j++;
	}
}

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->array = 0;
	stack_b->size = 0;
	stack_b->array = 0;
}

void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
	{
		write(1, "Error!\n", 8);
		exit (1);
	}
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]) || (ft_atol(argv[i]) > INT32_MAX))
			{
				write(1, "Error!\n", 8);
				exit (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
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
	stack_a->size += 1;
	if (check_stack(argv, stack_a, stack_b) == 1)
	{
		stack_a->array[stack_a->size - 1] = ft_atoi(argv);
	}
	else
		stack_a->size -= 1;
	return (stack_a->size);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;
	int		j;

	i = 1;
	j = 0;
	check_args(argc, argv);
	initialize_stacks(&stack_a, &stack_b);
	stack_a.size = 0;
	stack_a.array = ft_calloc((argc - 1), sizeof(int));
	stack_b.size = 0;
	stack_b.array = ft_calloc((argc - 1), sizeof(int));
	while (argv[i])
	{
		stack_a.size = fill_stack(argv[i], &stack_a, &stack_b);
		i++;
		j++;
	}
	//acaba aqui a funcao, apagar a partir daqui
	/*i = 1;
	j = 0;
	while (argv[i])
	{
		stack_b.size = fill_stack(argv[i], &stack_b, &stack_a);
		i++;
		j++;
	}
	j = 0;*/
	print_stacks(stack_a, stack_b);
	printf("%s", "\n\n");
	//sa(&stack_a);
	//sb(&stack_b);
	//ss(&stack_a, &stack_b);
	//pa(&stack_a, &stack_b);
	//pb(&stack_a, &stack_b);
	//ra(&stack_a);
	//rb(&stack_b);
	//rr(&stack_a, &stack_b);
	//rra(&stack_a);
	//rrb(&stack_b);
	//rrr(&stack_a, &stack_b);
	ft_printf("Operations: %d\n\n", sort_3_numbers(&stack_a));
	print_stacks(stack_a, stack_b);
	free(stack_a.array);
	free(stack_b.array);
	return (0);
}
