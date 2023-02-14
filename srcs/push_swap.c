/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:58:00 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/02/14 11:46:31 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;
	int		j;

	i = 1;
	j = 0;
	//check_args(argc, argv);
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
	if (stack_a.size == 2)
	{
		ft_printf("Operations: %d\n\n", sort_2_numbers(&stack_a));
	}
	else if (stack_a.size == 3)
	{
		ft_printf("Operations: %d\n\n", sort_3_numbers(&stack_a));
	}
	else if (stack_a.size == 5)
	{
		ft_printf("Operations: %d\n\n", sort_5_numbers(&stack_a, &stack_b));
	}
	else
	{
		ft_printf("Operations: %d\n\n", sort_numbers(&stack_a, &stack_b));
	}
	print_stacks(stack_a, stack_b);
	free(stack_a.array);
	free(stack_b.array);
	return (0);
}