/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:37:18 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/20 16:33:38 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	j = 0;
	if (argc < 2)
	{
		ft_printf("%s", "Please introduce a valid number of arguments!");
		return (0);
	}
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("%s", "Not all the arguments are numbers!");
				return (0);
			}
			j++;
		}
		i++;
	}
	start_stacks(argc, *argv, stack_a, stack_b);
	return (0);
}
