/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:58:00 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/20 13:02:24 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*print stacks for testing purposes*/
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
		if (stack_a.array[0] == 0)
		{
			printf("%s", "(null)");
			break ;
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
		if (stack_b.array[0] == 0)
		{
			printf("%s", "(null)");
			break ;
		}
		printf("%d", stack_b.array[j]);
		printf("%s", "|");
		j++;
	}
}

/*if x arguments, call different functions*/
void	call_sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_2_numbers(stack_a);
	else if (stack_a->size == 3)
		sort_3_numbers(stack_a);
	else if (stack_a->size == 5)
		sort_5_numbers(stack_a, stack_b);
	else
		sort_rest_numbers(stack_a, stack_b);
}

/*check how many args are passed*/
void	args_handle(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc > 2)
	{
		while (argv[i])
		{
			stack_a->size = fill_stack(argv[i], stack_a, stack_b);
			i++;
			j++;
		}
	}
	else if (argc == 2)
	{
		stack_a->size = fill_stack_split(argv[1], stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	initialize_stacks(&stack_a, &stack_b);
	stack_a.size = 0;
	stack_a.array = ft_calloc((argc - 1), sizeof(int));
	stack_b.size = 0;
	stack_b.array = ft_calloc((argc - 1), sizeof(int));
	args_handle(argc, argv, &stack_a, &stack_b);
	call_sort_stacks(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	free(stack_a.array);
	free(stack_b.array);
	return (0);
}
